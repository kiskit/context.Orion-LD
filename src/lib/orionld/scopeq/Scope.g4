grammar Scope;

// Parser
scope  : (SCOPESEPARATOR)? scopelevel (SCOPESEPARATOR scopelevel)*  // [%x2F] ScopeQLevel *(%x2F ScopeQLevel)
    ;
scopelevel : IDENTIFIER
    ;

// Lexer
SCOPESEPARATOR : '/' ;
IDENTIFIER: [a-zA-Z\u0080-\ufffe][_0-9a-zA-Z\u0080-\ufffe]*; // no real solution for this "unicode letter" and "unicode digit" thing so we accept ASCII letters or any unicode character as first character followed by any letter or digit or unicode characters
