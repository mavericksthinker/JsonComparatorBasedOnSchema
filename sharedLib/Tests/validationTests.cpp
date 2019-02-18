//
// Created by mavericks on 5/25/18.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../library.h"
#include <iostream>
using testing::Eq;
using namespace std;
namespace {
    class ClassDeclarations:public testing::Test{
    public:
        Validation v;
        ClassDeclarations(){
            v;

        }
    };
}

//Tests for Email

TEST_F(ClassDeclarations,A_valid_format_of_email_id_should_return_true_bishalsahoo_gmail_com){

    bool a=Validation::checkEmailValid("bishalsahoo@gmail.com");
    bool expected=true;
    ASSERT_EQ(expected,a);
    cout<<"valid format of email bishalsahoo@gmail.com"<<endl<<endl;
}


TEST_F(ClassDeclarations,A_valid_format_of_email_id_should_return_true_joshuabeckers_gmail_com){

    bool a=Validation::checkEmailValid("joshuabeckers@gmail.com");
    bool expected=true;
    ASSERT_EQ(expected,a);
    cout<<"valid format of email joshuabeckers@gmail.com"<<endl<<endl;
}

TEST_F(ClassDeclarations,A_valid_format_of_email_id_should_return_true_hottab_gmail_com){

    bool a=Validation::checkEmailValid("hottab@gmail.com");
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"valid format of email hottab@gmail.com"<<endl<<endl;
}

TEST_F(ClassDeclarations,An_invalid_format_of_email_id_should_return_false_bis_halsahoo_gmail_com){

    bool a=Validation::checkEmailValid("bis@halsahoo@gmail.com");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of email bis@halsahoo@gmail.com"<<endl<<endl;
}

TEST_F(ClassDeclarations,An_invalid_format_of_email_id_should_return_false){

    bool a=Validation::checkEmailValid("bishal..sahoo@gmail.com");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of email bishal..sahoo@gmail.com"<<endl<<endl;
}

TEST_F(ClassDeclarations,An_invalid_format_of_email_id_should_return_false_bishalsahoo_gmail_c){

    bool a=Validation::checkEmailValid("bishalsahoo@gmail.c");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of email bishalsahoo@gmail.c"<<endl<<endl;
}
//Tests For Phone number


TEST_F(ClassDeclarations,Valid_format_phone_number_91_9178902119){

    bool a=Validation::checkPhoneValid("+91 9178902119");
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"valid format of phone format(+91 9178902119)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Valid_format_phone_number_919178902119){

    bool a=Validation::checkPhoneValid("+919178902119");
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"valid format of phone format(+919178902119)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Valid_format_phone_number_541_754_3010){

    bool a=Validation::checkPhoneValid("(541)754-3010");
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"valid format of phone format((541)754-3010)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Valid_format_phone_number_1_541_754_3010) {

    bool a = Validation::checkPhoneValid("+1-541-754-3010");
    bool expected = true;
    ASSERT_EQ(expected, a);cout<<"valid format of phone format(+1-541-754-3010)"<<endl<<endl;
}
TEST_F(ClassDeclarations,Valid_format_phone_number__191_541_754_3010){

    bool a=Validation::checkPhoneValid("@191 541 754 3010");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of phone format(@191 541 754 3010)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Invalid_format_phone_number_541_754_3010){

    bool a=Validation::checkPhoneValid("541| 754 3010");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of phone format(541| 754 3010)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Invalid_format_phone_Number_541_754_3010){

    bool a=Validation::checkPhoneValid("541| 754-3010");
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Invalid format of phone format(541| 754-3010)"<<endl<<endl;
}

//json string comparison Tests


TEST_F(ClassDeclarations,Test1_Item1_is_equal_to_Item2){
    const char *item1 = "{  \"array\": [    1,    2,    3  ],  \"boolean\": true,  \"null\": null,  \"number\": 123,  \"object\": {    \"a\": \"b\",    \"c\": \"d\",    \"e\": \"f\"  },  \"string\": \"Hello World\",   \"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\" }    ]}      ]}";
    const char *item2 = "{ \"array\": [    1,    2,    3  ],   \"justsomedata\": true,  \"boolean\": true,  \"null\": null,  \"object\": {    \"a\": \"b\",    \"c\": \"d\",    \"e\": \"f\"  },  \"number\": 123,  \"object_array\": [     {\"whatever\": \"test\", \"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ],  \"string\": \"Hello World\"}";
    const char *temp = "{  \"array\": [    null  ],  \"boolean\": null,  \"null\": null,  \"object\": {    \"a\": null,    \"c\": null,    \"e\": null  },  \"number\": null,  \"object_array\": [     {\"key\": null }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": null },     {\"key\": null },     {\"key\": null }    ]}      ],  \"string\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be"<<expected<<"Now working successfully "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test2_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{  \"array\": [    1,    2,    3  ],  \"boolean\": true,  \"null\": null,  \"number\": 123,  \"object1\": {    \"a\": \"b\",    \"c\": \"d\",    \"e\": \"f\"  },  \"string\": \"Hello World\",   \"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\" }    ]}      ]}";
    const char *item2 = "{ \"array\": [    1,    2,    3  ],   \"justsomedata\": true,  \"boolean\": true,  \"null\": null,  \"object\": {    \"a\": \"b\",    \"c\": \"d\",    \"e\": \"f\"  },  \"number\": 123,  \"object_array\": [     {\"whatever\": \"test\", \"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ],  \"string\": \"Hello World\"}";
    const char *temp = "{  \"array\": [    null  ],  \"boolean\": null,  \"null\": null,  \"object\": {    \"a\": null,    \"c\": null,    \"e\": null  },  \"number\": null,  \"object_array\": [     {\"key\": null }    ],    \"deep_nested_array\": [        {\"object_array\": [     {\"key\": null },     {\"key\": null },     {\"key\": null }    ]}      ],  \"string\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be"<<expected<<"and pass with value false"<<endl<<endl;
}


TEST_F(ClassDeclarations,Test3_Item1_is_equal_to_Item2){

    const char *item1 = "{ \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\" }    ]}      ]}";
    const char *item2 = "{  \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ]}";
    const char *temp = "{\"deep_nested_array\": [        {\"object_array\": [     {\"key\": null },     {\"key\": null },     {\"key\": null } ]} ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"Now working successfully "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test4_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{ \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]}     ]}";
    const char *item2 = "{  \"deep_nested_array\": [        {\"object_array\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]},    {\"object_array\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ]}";
    const char *temp = "{\"deep_nested_array\": [        {\"object_array\": [     {\"key\": null },     {\"key\": null },     {\"key\": null } ]} ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and passed with value false"<<endl<<endl;
}

TEST_F(ClassDeclarations,Test5_Item1_is_equal_to_Item2){

    const char *item1 = "{ \"deep_nested_array\": [{\"object_array2\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\" }    ]}      ]}";
    const char *item2 = "{  \"deep_nested_array\": [ {\"object_array2\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ]}";
    const char *temp = "{\"deep_nested_array\": [{\"object_array2\": [     {\"key\": null },     {\"key\": null },     {\"key\": null } ]} ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and now working as the bug is fixed "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test6_Item1_is_not_equal_to_Item2_based_on_the_template){

    const char *item1 = "{ \"deep_nested_array\": [{\"object_array3\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\" }    ]}      ]}";
    const char *item2 = "{  \"deep_nested_array\": [ {\"object_array2\": [     {\"key\": \"value4\" },     {\"key\": \"value5\" },     {\"key\": \"value6\", \"ignoreme\": 12346 }    ]}      ]}";
    const char *temp = "{\"deep_nested_array\": [{\"object_array2\": [     {\"key\": null },     {\"key\": null },     {\"key\": null } ]} ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and passed with value false"<<endl<<endl;
}


TEST_F(ClassDeclarations,Test7_Item1_is_equal_to_Item2){

    const char *item1 = "{ \"deep_nested_array\": [        {\"object_array1\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]}]}";
    const char *item2 = "{  \"deep_nested_array\": [        {\"object_array1\": [     {\"key\": \"value1\" },     {\"key\": \"value2\" },     {\"key\": \"value3\" }    ]}]}";
    const char *temp = "{\"deep_nested_array\": [        {\"object_array1\": [     {\"key\": null },     {\"key\": null },     {\"key\": null } ]} ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value true(Successful) "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test8_Item1_is_equal_to_Item2){

    const char *item1 = "{  \"array\": [    1,    2,    3  ]}";
    const char *item2 = "{  \"array\": [    1,    2,    3  ]}";
    const char *temp = "{  \"array\": [    null  ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value true(Successful)"<<endl<<endl;
}

TEST_F(ClassDeclarations,Test9_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{  \"array\": [    1,    2,    3  ]}";
    const char *item2 = "{  \"array\": [    1,    0,    3  ]}";
    const char *temp = "{  \"array\": [    null  ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value false(Successful)Due to different values in the array "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test10_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{   \"null\": 2}";
    const char *item2 = "{   \"null\": 1}";
    const char *temp = "{     \"null\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful)Due to different value in the null "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test11_Item1_is_equal_to_Item2){

    const char *item1 = "{\"null\": null}";
    const char *item2 = "{\"justsomedata\": true,\"null\": null}";
    const char *temp = "{\"null\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value true(Successful) "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test12_Item1_is_equal_to_Item2){

    const char *item1 = "{   \"boolean\": true}";
    const char *item2 = "{   \"justsomedata\": true,  \"boolean\": true}";
    const char *temp = "{   \"boolean\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value true(Successful)Due to same value "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test13_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{   \"boolean\": true}";
    const char *item2 = "{   \"justsomedata\": true,  \"boolean\": false}";
    const char *temp = "{   \"boolean\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected=false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful)Due to boolean value is different "<<endl<<endl;
}
//This also might create bug if it has more nested array or string or objects......
TEST_F(ClassDeclarations,Test14_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{ \"object\": {    \"a\": \"b\",   \"e\": \"f\"  }}";
    const char *item2 = "{  \"object\": {    \"c\": \"b\",   \"e\": \"f\"  }}";
    const char *temp = "{ \"object\": { \"c\": null,    \"e\": null  }}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value false(Successful)Due to Different values in the object ie \"c\" "<<endl<<endl;

}

TEST_F(ClassDeclarations,Test15_Item1_is_equal_to_Item2){

    const char *item1 = "{ \"object\": {    \"a\": \"b\",   \"e\": \"f\"  }}";
    const char *item2 = "{  \"object\": {    \"a\": \"b\",   \"e\": \"f\"  }}";
    const char *temp = "{ \"object\": { \"a\": null,\"e\": null}}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value true(Successful)Due to equal value inside the object "<<endl<<endl;

}

TEST_F(ClassDeclarations,Test16_Item1_is_equal_to_Item2){

    const char *item1 = "{ \"string\": \"Hello World\"}";
    const char *item2 = "{ \"string\": \"Hello World\"}";
    const char *temp = "{\"string\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value true(Successful) Due to equal string value "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test17_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{ \"string\": \"Hello World\"}";
    const char *item2 = "{ \"string\": \"Hi World\"}";
    const char *temp = "{\"string\": null}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful) Due to unequal string value "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test18_Item1_is_notequal_to_Item2_based_on_the_template){

    const char *item1 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,       \"releaseDate\": \"2014-06-25T00:00:00.000Z\",       \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          } ,          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              5,              null            ]          }     ]      }    }";
    const char *item2 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          },          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";
    const char *temp = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [                 {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful) Due to unequal string value "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test19_Item1_is_equal_to_Item2){

    const char *item1 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,       \"releaseDate\": \"2014-06-25T00:00:00.000Z\",       \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          } ,          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }     ]      }    }";
    const char *item2 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          },          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";
    const char *temp = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [                 {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";



    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value true(Successful) Due to equal  value "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test20_Item1_is_notequal_to_Item2_based_on_the_template_due_to_absence_of_a_key_in_item2){

    const char *item1 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,       \"releaseDate\": \"2014-06-25T00:00:00.000Z\",       \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          } ,          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }     ]      }    }";
    const char *item2 = "{      \"product\": \"Live JSON generator\",         \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          },          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";
    const char *temp = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [                 {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful) Due to no version key in the item2 "<<endl<<endl;
}

TEST_F(ClassDeclarations,Test21_Item1_is_notequal_to_Item2_based_on_the_template_due_to_Unequal_array_in_item1){

    const char *item1 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,       \"releaseDate\": \"2014-06-25T00:00:00.000Z\",       \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [                {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }     ]      }    }";
    const char *item2 = "{      \"product\": \"Live JSON generator\",         \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          },          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";
    const char *temp = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [                 {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= false;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value false(Successful) Due to unequal array in item1 "<<endl<<endl;
}
TEST_F(ClassDeclarations,Test22_Item1_is_equal_to_Item2_because_whole_string_comparison_should_happen){

    const char *item1 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,       \"releaseDate\": \"2014-06-25T00:00:00.000Z\",       \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          } ,          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }     ]      }    }";
    const char *item2 = "{      \"product\": \"Live JSON generator\",      \"version\": 3.1,      \"releaseDate\": \"2014-06-25T00:00:00.000Z\",      \"demo\": true,      \"person\": {        \"id\": 12345,        \"name\": \"John Doe\",        \"phones\": {          \"home\": \"800-123-4567\",          \"mobile\": \"877-123-1234\"        },        \"email\": [          \"jd@example.com\",          \"jd@example.org\"        ],        \"dateOfBirth\": \"1980-01-02T00:00:00.000Z\",        \"registered\": true,        \"emergencyContacts\": [          {            \"name\": \"Jane Doe\",            \"phone\": \"888-555-1212\",            \"relationship\": \"spouse\",            \"alternativeContacts\": [              \"test\",              \"123\",              \"some\\\"char\"            ]          },          {            \"name\": \"Justin Doe\",            \"phone\": \"877-123-1212\",            \"relationship\": \"parent\",            \"alternativeContacts\": [              3,              null            ]          }        ]      }    }";
    const char *temp = "null";



    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<" and test passed with Value true(Successful) Due to equal  value "<<endl<<endl;
}
TEST_F(ClassDeclarations,Test23_Item1_is_equal_to_Item2_as_arrays_are_equal){

    const char *item1 = "{  \"array\": [    { \"x\": [1,2,2]},    2,    3  ]}";
    const char *item2 = "{  \"array\": [    { \"x\": [1,2,2]},   2,    3  ]}";
    const char *temp = "{  \"array\": [    null  ]}";


    bool a=Validation::isEqualItem(item1,item2,temp);
    bool expected= true;
    ASSERT_EQ(expected,a);cout<<"Expected to be "<<expected<<"and test passed with Value true(Successful)Due to different values in the array "<<endl<<endl;
}