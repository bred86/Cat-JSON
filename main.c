#include <stdio.h>
#include "catjson.h"

int main (int argc, char ** argv)
{
    char str1[1] = "{";
    char str2[2] = "{{";

    char ** ret_array;
    st_head * json_runner;

    json_runner = loadJson(str1);
    ret_array = getFieldValue(json_runner, "nome1");
    printf("%s - %s\n", ret_array[0], ret_array[1]);

    json_runner = loadJson(str2);
    ret_array = getFieldValue(json_runner, "nome2");
    printf("%s - %s\n", ret_array[0], ret_array[1]);

    /*json_runner = create_structure();

    setFieldValues(json_runner, "nome", "string", "Fred");

    ret_array = getFieldValue(json_runner, "nome");

    printf("%s - %s\n", ret_array[0], ret_array[1]);*/

    return 0;
}
