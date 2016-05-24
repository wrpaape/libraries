#include "nlg.h"

extern inline char *
sample_word_group(const struct WordGroup *const restrict group);

static const struct WordGroup
PERSONAL_PRONOUNS[PERSONAL_PRONOUN_TYPES][PERSON_TYPES][NUMBER_TYPES] = {
	[SUBJECT] = {
		[FIRST]  = {
			[SINGULAR] = {
				.words = {
					"I"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"we"
				},
				.i_max = 0ul
			}
		},
		[SECOND] = {
			[SINGULAR] = {
				.words = {
					"you"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"you", "you all", "y'all", "you guys",
					"you lot", "you people"
				},
				.i_max = 5ul
			}
		},
		[THIRD]  = {
			[SINGULAR] = {
				.words = {
					"he", "she", "it", "they"
				},
				.i_max = 3ul
			},
			[PLURAL]   = {
				.words = {
					"they"
				},
				.i_max = 0ul
			}
		}
	},
	[OBJECT] = {
		[FIRST]	 = {
			[SINGULAR] = {
				.words = {
					"me"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"us"
				},
				.i_max = 0ul
			}
		},
		[SECOND] = {
			[SINGULAR] = {
				.words = {
					"you"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"you", "you all", "y'all", "you guys",
					"you lot", "you people"
				},
				.i_max = 5ul
			}
		},
		[THIRD]  = {
			[SINGULAR] = {
				.words = {
					"him", "her", "it", "them"
				},
				.i_max = 3ul
			},
			[PLURAL]   = {
				.words = {
					"them"
				},
				.i_max = 0ul
			}
		}
	},
	[DEPENDENT_POSSESSIVE] = {
		[FIRST]	 = {
			[SINGULAR] = {
				.words = {
					"my"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"our"
				},
				.i_max = 0ul
			}
		},
		[SECOND] = {
			[SINGULAR] = {
				.words = {
					"your"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"your", "y'all's"
				},
				.i_max = 1ul
			}
		},
		[THIRD]  = {
			[SINGULAR] = {
				.words = {
					"his", "her", "its", "their"
				},
				.i_max = 3ul
			},
			[PLURAL]   = {
				.words = {
					"their"
				},
				.i_max = 0ul
			}
		}
	},
	[INDEPENDENT_POSSESSIVE] = {
		[FIRST]	 = {
			[SINGULAR] = {
				.words = {
					"mine"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"ours"
				},
				.i_max = 0ul
			}
		},
		[SECOND] = {
			[SINGULAR] = {
				.words = {
					"yours"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"yours"
				},
				.i_max = 0ul
			}
		},
		[THIRD]  = {
			[SINGULAR] = {
				.words = {
					"his", "hers", "its", "theirs"
				},
				.i_max = 3ul
			},
			[PLURAL]   = {
				.words = {
					"theirs"
				},
				.i_max = 0ul
			}
		}
	},
	[REFLEXIVE] = {
		[FIRST]	 = {
			[SINGULAR] = {
				.words = {
					"myself"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"ourselves"
				},
				.i_max = 0ul
			}
		},
		[SECOND] = {
			[SINGULAR] = {
				.words = {
					"yourself"
				},
				.i_max = 0ul
			},
			[PLURAL]   = {
				.words = {
					"yourselves"
				},
				.i_max = 0ul
			}
		},
		[THIRD]  = {
			[SINGULAR] = {
				.words = {
					"himself", "herself", "itself", "themselves"
				},
				.i_max = 3ul
			},
			[PLURAL]   = {
				.words = {
					"themselves"
				},
				.i_max = 0ul
			}
		}
	}
};

static const struct WordGroup
DEMONSTRATIVES[NUMBER_TYPES] = {
	[SINGULAR] = {
		.words = {
			"this", "that"
		},
		.i_max = 1ul
	},
	[PLURAL] = {
		.words = {
			"these", "those"
		},
		.i_max = 1ul
	}
};

static const char *const AUXILIARY_VERBS[] = {
	"be", "am", "are", "is", "was", "were", "being", "been",
	"can",
	"could",
	"dare",
	"do", "does", "did",
	"have", "has", "had", "having",
	"may",
	"might",
	"must",
	"need",
	"ought",
	"shall",
	"should",
	"will",
	"would"
};




static const char *const VERBS[] = {
	"be",
	"have",
	"do",
	"say",
	"get",
	"make",
	"go",
	"know",
	"take",
	"see",
	"come",
	"think",
	"look",
	"want",
	"give",
	"use",
	"find",
	"tell",
	"ask",
	"work",
	"seem",
	"feel",
	"try",
	"leave",
	"call"
};

static const char *const NOUNS[][2] = {
	"time",	       "times",
	"year",	       "years",
	"people",      "peoples",
	"way",	       "ways",
	"day",	       "days",
	"man",         "men",
	"thing",       "things",
	"woman",       "women",
	"life",        "lives",
	"child",       "children",
	"world",       "worlds",
	"school",      "schools",
	"state",       "states",
	"family",      "families",
	"student",     "students",
	"group",       "groups",
	"country",     "countries",
	"problem",     "problems",
	"hand",        "hands",
	"part",        "parts",
	"place",       "places",
	"case",        "cases",
	"week",        "weeks",
	"company",     "companies",
	"system",      "systems",
	"program",     "programs",
	"question",    "questions",
	"work",        "works",
	"government",  "governments",
	"number",      "numbers",
	"night",       "nights",
	"point",       "points",
	"home",        "homes",
	"water",       "waters",
	"room",        "rooms",
	"mother",      "mothers",
	"area",        "areas",
	"money",       "monies",
	"story",       "stories",
	"fact",        "facts",
	"month",       "months",
	"lot",         "lots",
	"right",       "rights",
	"study",       "studies",
	"book",        "books",
	"eye",         "eyes",
	"job",         "jobs",
	"word",        "words",
	"business",    "businesses",
	"issue",       "issues",
	"side",        "sides",
	"kind",        "kinds",
	"head",        "heads",
	"house",       "houses",
	"service",     "services",
	"friend",      "friends",
	"father",      "fathers",
	"power",       "powers",
	"hour",        "hours",
	"game",        "games",
	"line",        "lines",
	"end",         "ends",
	"member",      "members",
	"law",         "laws",
	"car",         "cars",
	"city",        "cities",
	"community",   "communities",
	"name",        "names",
	"president",   "presidents",
	"team",        "teams",
	"minute",      "minutes",
	"idea",        "ideas",
	"kid",         "kids",
	"body",        "bodies",
	"information", "information",
	"back",        "backs",
	"parent",      "parents",
	"face",        "faces",
	"other",       "others",
	"level",       "levels",
	"office",      "offices",
	"door",        "doors",
	"health",      "healths",
	"person",      "people",
	"art",         "arts",
	"war",         "wars",
	"history",     "histories",
	"party",       "parties",
	"result",      "results",
	"change",      "changes",
	"morning",     "mornings",
	"reason",      "reasons",
	"research",    "research",
	"girl",        "girls",
	"guy",         "guys",
	"moment",      "moments",
	"air",         "air",
	"teacher",     "teachers",
	"force",       "forces",
	"education",   "educations"
};

static const char *const ARTICLES[] = {
	"the", "a", "an"
};

static const char *const PERSONAL_PRONOUNS[] = {
};


/* To get a Sentence, append a Noun-Phrase and a Verb-Phrase To get a Noun-Phrase, append a n Article and a Noun */
/* Choose "the" for the Article */
/* Choose "man" for the Noun */
/* The resultingrNoun-Phraseis"the man" */
/* Togeta Verb-Phrase,appenda VerbandaNoun-Phrase */
/* Choose "hit" for the Verb */
/* To get a Noun-Phrase, append a n Article and a Noun */
/* Choose"the"for theArticle */
/* Choose"ball" for the Noun */
/* The resulting Noun-Phrase is "the ball" The resulting Verb-Phrase is "hit the ball" */
/* The resulting Sentence is "The man hit the ball" */

