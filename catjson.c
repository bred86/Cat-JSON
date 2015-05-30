#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct json {
  int level;
  int field_position;

  char * field_value_type;
  char * field_name;
  char * field_value;

  struct json * p_next_element;
  struct json * p_next_level;
  struct json * p_previous_element;
  struct json * p_previous_level;

} st_json;

typedef struct head {
  st_json * p_initial;
  st_json * p_current;
} st_head;

st_json * createJSONCell () {
  st_json * structure = (st_json*) malloc(sizeof(st_json));
  if (structure == NULL) {
    printf("[Error 255] Something gone bad creating the JSON structure");
    exit(255);
  }

  structure->p_next_element = NULL;
  structure->p_next_level = NULL;
  structure->p_previous_element = NULL;
  structure->p_previous_level = NULL;

  return structure;
}

st_head * createJSONHead (st_json * json_structure) {
    st_json * json_tmp;

    st_head * json_head = (st_head*) malloc(sizeof(st_head));
    if (json_head == NULL) {
      printf("[Error 256] Something gone bad creating the JSON head structure");
        exit(256);
    }

    if (json_structure == NULL) {
        json_tmp = createJSONCell();
    }
    else {
        json_tmp = json_structure;
    }

    json_head->p_initial = json_tmp;
    json_head->p_current = json_tmp;


    return json_head;
}

char ** getFieldValue (st_head * json_head, char * field_name) {
    char * returned_field_name;
    char * returned_field_type;

    char ** returned_value = malloc (2*sizeof(char *));

    if (strcmp(field_name, json_head->p_current->field_name) == 0) {
        returned_value[0] = (char *) malloc(strlen(json_head->p_current->field_name)*sizeof(char*)+1);
        strcpy(returned_value[0], json_head->p_current->field_value);

        returned_value[1] = (char *) malloc(strlen(json_head->p_current->field_value_type)*sizeof(char*)+1);
        strcpy(returned_value[1], json_head->p_current->field_value_type);
    }

    return returned_value;
}

void setFieldValues (st_head * json_head, char * field_name, char * field_value_type, char * field_value) {
    json_head->p_current->field_name = (char*) malloc(strlen(field_name)*sizeof(char*));
    json_head->p_current->field_value_type = (char*) malloc(strlen(field_value_type)*sizeof(char*));
    json_head->p_current->field_value = (char*) malloc(strlen(field_value)*sizeof(char*));

    strcpy(json_head->p_current->field_name, field_name);
    strcpy(json_head->p_current->field_value_type, field_value_type);
    strcpy(json_head->p_current->field_value,field_value);

}

st_head * loadJson (char * json_string) {
    int num;

    st_json * json_cell = NULL;
    st_head * json_head = NULL;

    for (num = 0; num <= strlen(json_string); num++) {
        if ((json_string[num] == '{') && (json_head == NULL)) {
            json_head = createJSONHead(NULL);
            json_head->p_current->level = 1;
            setFieldValues(json_head, "nome1", "string", "Fred");
        }
        else if (json_string[num] == '{') {
            json_cell = createJSONCell();
            json_head->p_current->p_next_level = json_cell;
            json_head->p_current->p_next_level->p_previous_level = json_head->p_current;
            json_head->p_current->p_next_level->level = json_head->p_current->level + 1;
            setFieldValues(json_head, "nome2", "string", "Mariana");
        }
    }

    return json_head;
}
