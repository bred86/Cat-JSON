#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "catjson.h"

int main (int argc, char ** argv)
{
    char * str1;
    char * str2;

    char ** ret_array;

    st_head * json_runner;

    str1 = (char*) malloc(strlen("{\"field\":\"test\"}")*sizeof(char));
    str2 = (char*) malloc(strlen("{\"level\":\"1\", \"field\":{\"level\":\"2\"}}")*sizeof(char));

    strcpy(str1,"{\"field\":\"test\"}");
    json_runner = loadJson(str1);
    ret_array = getFieldValue(json_runner, "field");
    printf("%s - %s - %s\n", ret_array[0], ret_array[1], ret_array[2]);

    // strcpy(str2, "{\"level\":\"1\", \"field\":{\"level\":\"2\"}}");
    // json_runner = loadJson(str2);
    // ret_array = getFieldValue(json_runner, "nome2");
    // printf("%s - %s - %s\n", ret_array[0], ret_array[1], ret_array[2]);

    /*json_runner = create_structure();

    setFieldValues(json_runner, "nome", "string", "Fred");

    ret_array = getFieldValue(json_runner, "nome");

    printf("%s - %s\n", ret_array[0], ret_array[1]);*/

    return 0;
}
