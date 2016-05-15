#include <string/generate.h>



static const char *const VERBS[][3][2] = {
	{"", "be"},
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

static const char *const PERSONAL_PRONOUNS[]


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

