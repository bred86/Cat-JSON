/*
# ##############################################
#
# ##############################################
*/
typedef struct json st_json;

/*
# ##############################################
#
# ##############################################
*/
typedef struct head st_head;

/*
# ##############################################
#
# ##############################################
*/
st_json * createJSONCell ();

/*
# ##############################################
#
# ##############################################
*/
st_head * createJSONHead (st_json * json_structure);

/*
# ##############################################
#
# ##############################################
*/
char ** getFieldValue (st_head * json_head, char * field_name);

/*
# ##############################################
#
# ##############################################
*/
void setFieldValues (st_head * json_head, char * field_name, char * field_value_type, char * field_value);

/*
# ##############################################
#
# ##############################################
*/
st_head * loadJson (char * json_string);
