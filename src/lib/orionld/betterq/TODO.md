## MUST
* Fix memory leaks (should be done, but cases may remain pointed out)
* Clean q vs betterq (requires to pick whatever is needed in q, put it in betterq, remove q, rename betterq), replace qCheck by qCheck2
* Check qVariableFix stuff. The grammar takes responsibility for part of it (brackets count) but we could probably do it in the parsing (e.g. append .value to first level and such). The grammar/parser can probably be made to understand the different cases.
* Attribute names should be unicode letters. Not sure how to do that, grammar or not
* remove qPrint from logs
* fix !~= (mongo doesn't like it at least in 3.6.8). Maybe add negative lookahead in regex if all else fails
* have a look at how createdAt and such are handled 

## SHOULD
* Handle priorities (AND and OR) through grammar
* Add compilation for grammar in cmake (java -jar ~/Development/antlr/antlr-4.9.2-complete.jar -Dlanguage=Cpp Query). Fair warning, changing ANTLR version may result in some mild to average pain.
* Remove printing stuff from lib (qPrint)
* Separate stack management utility functions into its own file, maybe make a nice QNode* stack class 
* Logical operators priority should be handled by grammar
## NICE TO HAVE
* Simplify logical operators hierarchy (factorize AND and OR nodes) (requires either to modify the algorithm, and I'd rather not, or to add another loop at the end or exitQuery)

## Why switch to grammar
* Many things handled by parser (lexical and syntax errors, bracket counting, escape chars)
* Same lexing/parsing structure for all grammars
* Easier evolutions
* Fixes a few bugs 
  * Accurate handling of AND and OR operators and priorities
  * Numbers handled according to specs (-10.2E-3)
  * More robust grammar handling
  Try _field==""value""_:
  (no error)
  * Better escape chars management (although we fixed it in your qLex too for regex)
  Try _field=="\"value\""_: understood as \ 
  * Should fix a.b[c.d] but doesn't because of qVariableFix. Doc says: _EXAMPLE 10: sensor.rawdata[airquality.particulate]==40_ and ABNF allows it. Should be either expunged from the doc or allowed in qVariableFix. 
  * More robust regex handling (requires RE()). In any case, for now, our version is compliant with ABNF
  Try _field~=^[2|3]0..$_:
  (with docker)
  -> _qParse: parse error: unsupported node type: Range_
```json
{
    "type": "https://uri.etsi.org/ngsi-ld/errors/BadRequestData",
    "title": "parse error: unsupported node type",
    "detail": "Range"
}
```
(in IDE)
-> _qParse: parse error: unsupported node type: Range_
```json
{
    "type": "https://uri.etsi.org/ngsi-ld/errors/BadRequestData",
    "title": "Invalid Q-Filter",
    "detail": "Range"
}
```
