<?php
require('library.php');
var_dump("Checking of the email validation function");
$b=new validation();
$string ="john@gmail.com";
var_dump($b->checkEmailValid($string));
var_dump("checking of the phone validation function");
//$b=new validation();
$string ="91 78902009";
var_dump($b->checkPhoneValid($string));
var_dump("checking of the isEqualItem function");
$myObj1->name = "Bigshaq";
$myObj1->age = 30;
//$myObj1->city = "New York";
$myObj1->working1="successful";
$myObj1->arrays=[1,2,3];
$myJSON1 = json_encode($myObj1);

$myObj3->name = "Bigshaq";
$myObj3->working1="successful";
$myObj3->age = 30;
$myObj3->city = "News York";
$myObj3->working="successful";
$myObj3->arrays=[1,5,3];
$myJSON4 = json_encode($myObj3);
$myObj4->name = "Bigshaq";
$myObj4->age = 32;
$myObj4->working1="string";
//$myObj4->city = "New York";
$myObj4->arrays=[1,2,6];
$myJson3=json_encode($myObj4);

var_dump($b->isEqualItem($myJSON1, $myJSON4,$myJson3));
var_dump("checking of isEqualItem function");

$json1 = json_encode(array(
     "client" => array(
        "build" => "1.0",
        "name" => "xxxxxx",
        "version" => "1.0",
        "working" =>"successful"
     ),
     "protocolVersion" => 4,
     "data" => array(
        "distributorId" => "xxxx",
        "distributorPin" => "xxxx",
        "locale" => "en-US"
     )
));
$json2 = json_encode(array(
     "client" => array(
        "build" => "1.0",
        "name" => "xxxxxx",
        "version" => "1.0"
     ),
     "protocolVersion" => 4,
     "data" => array(
        "distributorId" => "xxxx",
        "distributorPin" => "xxxx",
        "locale" => "en-US"
     )
));
$temp = json_encode(array(
     "client" => array(
        "build" => "1.0",
        "name" => "xxxxxx",
        "version" => "1.0"
     ),
     "protocolVersion" => 4,
     "data" => array(
        "distributorId" => "xxxx",
        "distributorPin" => "xxxx",
        "locale" => "en-US"
     )
));
var_dump($b->isEqualItem($json1, $json2,$temp));

var_dump("calculation Function Tests with Actual Order Jsonformat");
$calculate=new calculation();
$order=json_encode(json_decode('{
    "data": {
        "customer": {
            "address": null
        },
        "table": null,
        "items": [
            {
                "category": {
                    "id": "435f22a0-c505-11e7-854d-c9a1234cbf63",
                    "name": "Pizzadsadsa"
                },
                "id": "04dbaba0-3985-11e8-a4e9-1f0eb8a65d1c",
                "estimated_time": "0",
                "option_set": [],
                "taxes": [
                    {
                        "name": "phuc",
                        "all_categories": 1,
                        "value": 21,
                        "tax_type": 1,
                        "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 672890.82,
                        "cat_taxes": [],
                        "value_type": 0,
                        "cumulative": 1,
                        "default": 1,
                        "selected": true,
                        "translations": [
                            {
                                "id": 295,
                                "created_at": "2018-05-02 04:43:43",
                                "name": "phuc",
                                "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                                "updated_at": "2018-05-02 04:43:43"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1
                    },
                    {
                        "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 0,
                        "cat_taxes": [
                            {
                                "is_tax_set": 0,
                                "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                            }
                        ],
                        "value_type": 1,
                        "cumulative": 1,
                        "default": 0,
                        "selected": true,
                        "translations": [
                            {
                                "id": 314,
                                "created_at": "2018-05-04 07:50:31",
                                "name": "1223123",
                                "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                                "updated_at": "2018-05-04 07:50:31"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1,
                        "name": "1223123",
                        "all_categories": 0,
                        "value": 11,
                        "tax_type": 1
                    }
                ],
                "discount": [
                    {
                        "name": "phuc",
                        "all_categories": 1,
                        "value": 21,
                        "tax_type": 1,
                        "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 672890.82,
                        "cat_taxes": [],
                        "value_type": 0,
                        "cumulative": 1,
                        "default": 1,
                        "selected": true,
                        "translations": [
                            {
                                "id": 295,
                                "created_at": "2018-05-02 04:43:43",
                                "name": "phuc",
                                "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                                "updated_at": "2018-05-02 04:43:43"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1
                    },
                    {
                        "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 0,
                        "cat_taxes": [
                            {
                                "is_tax_set": 0,
                                "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                            }
                        ],
                        "value_type": 0,
                        "cumulative": 0,
                        "default": 0,
                        "selected": true,
                        "translations": [
                            {
                                "id": 314,
                                "created_at": "2018-05-04 07:50:31",
                                "name": "1223123",
                                "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                                "updated_at": "2018-05-04 07:50:31"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1,
                        "name": "1223123",
                        "all_categories": 0,
                        "value": 11,
                        "tax_type": 1
                    }
                ],
                "amount": 242,
                "type": 0,
                "total_discount": 0,
                "price": 60.5,
                "qty": 4,
                "pretax_price": 60.5,
                "unique_id": "78065ba0-58c0-11e8-8d14-0f31745c622b",
                "options": {
                    "breakdown": [],
                    "total": 0
                },
                "discounts": [],
                "total_tax": 50.82,
                "subtotal": 242,
                "total": 292.82,
                "name": "banh khao"
            },
            {
                "amount": 3204000,
                "type": 0,
                "total_discount": 0,
                "price": 10000,
                "qty": 2,
                "pretax_price": 10000,
                "unique_id": "780674c0-58c0-11e8-96d8-dd4f8e3edace",
                "options": {
                    "breakdown": [
                        {
                            "type": "option",
                            "id": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                            "price": 398000,
                            "name": "18 \""
                        },
                        {
                            "price": 398000,
                            "name": "18 \"",
                            "type": "option",
                            "id": "f04a1500-c506-11e7-98b6-dd035c35d0cc"
                        },
                        {
                            "name": "18 \"",
                            "type": "option",
                            "id": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                            "price": 398000
                        },
                        {
                            "id": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                            "price": 398000,
                            "name": "18 \"",
                            "type": "option"
                        }
                    ],
                    "total": 0
                },
                "discounts": [],
                "total_tax": 672840,
                "subtotal": 3204000,
                "total": 3876840,
                "name": "Tropic Thunder",
                "category": {
                    "name": "Pizzadsadsa",
                    "id": "435f22a0-c505-11e7-854d-c9a1234cbf63"
                },
                "id": "a73374c0-c506-11e7-a2c8-e7a54e3a7736",
                "estimated_time": "0",
                "option_set": [
                    {
                        "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                        "min_choice": 1,
                        "mandatory": "1",
                        "name": "Pizza Size",
                        "option": [
                            {
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "option_uuid": "08809140-2e5a-11e8-860c-5d835def37e1",
                                "trackable": 0,
                                "name": "size 30",
                                "is_original": 0,
                                "type": "option",
                                "price": -10000,
                                "created_at": "2018-03-23 05:21:25",
                                "updated_at": "2018-03-23 05:21:25"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                                "name": "18 \"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354152",
                                "price": 398000,
                                "created_at": "2017-11-09 11:32:04",
                                "updated_at": "2017-11-09 11:32:04",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "f9985040-c506-11e7-88a6-6fe86a83bca1",
                                "name": "12\"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354153",
                                "price": 288000,
                                "created_at": "2017-11-09 11:32:20",
                                "updated_at": "2017-11-09 11:32:20",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7"
                            }
                        ],
                        "id": "35589",
                        "created_at": "2017-11-09 11:31:08",
                        "multiple_choice": "0",
                        "updated_at": "2017-11-09 11:31:08",
                        "multiple_option": "0",
                        "max_choice": 1,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719"
                    },
                    {
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time",
                        "option": [
                            {
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "name": "Same time",
                                "is_original": 1,
                                "type": "option",
                                "id": "354155"
                            },
                            {
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "name": "Table Share",
                                "is_original": 1,
                                "type": "option"
                            },
                            {
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077",
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:02"
                            },
                            {
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2",
                                "name": "Hold",
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03"
                            },
                            {
                                "updated_at": "2017-11-09 11:32:21",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "trackable": 0,
                                "name": "Anytime",
                                "is_original": 1,
                                "type\n    ": "option",
                                "id": "354154",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:21"
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09",
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0",
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                    },
                    {
                        "name": "Pizza Size",
                        "option": [
                            {
                                "id": "354159",
                                "price": 398000,
                                "created_at": "2017-11-09 11:33:04",
                                "updated_at": "2017-11-09 11:33:04",
                                "opt_set_uuid": "e4c60c70-c506-11e7-92d4-a541ab86b065",
                                "trackable": 0,
                                "option_uuid": "13d52230-c507-11e7-b644-e9514597c4ef",
                                "name": "18 \"",
                                "is_original": 1,
                                "type": "option"
                            },
                            {
                                "updated_at": "2017-11-09 11:33:04",
                                "opt_set_uuid": "e4c60c70-c506-11e7-92d4-a541ab86b065",
                                "trackable": 0,
                                "option_uuid": "13f7aa90-c507-11e7-ab08-bd50f2e6dd14",
                                "name": "12\"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354160",
                                "price": 288000,
                                "created_at": "2017-11-09 11:33:04"
                            }
                        ],
                        "id": "35591",
                        "created_at": "2017-11-09 11:31:45",
                        "multiple_choice": "0",
                        "updated_at": "2017-11-09 11:31:45",
                        "multiple_option": "0",
                        "max_choice": 1,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "e4c60c70-c506-11e7-92d4-a541ab86b065",
                        "min_choice": 0,
                        "mandatory": "0"
                    },
                    {
                        "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                        "min_choice": 1,
                        "mandatory": "1",
                        "name": "Pizza Size",
                        "option": [
                            {
                                "name": "size 30",
                                "is_original": 0,
                                "type": "option",
                                "price": -10000,
                                "created_at": "2018-03-23 05:21:25",
                                "updated_at": "2018-03-23 05:21:25",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "trackable": 0,
                                "option_uuid": "08809140-2e5a-11e8-860c-5d835def37e1"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                                "name": "18 \"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354152",
                                "price": 398000,
                                "created_at": "2017-11-09 11:32:04",
                                "updated_at": "2017-11-09 11:32:04",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7"
                            },
                            {
                                "created_at": "2017-11-09 11:32:20",
                                "updated_at": "2017-11-09 11:32:20",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "trackable": 0,
                                "option_uuid": "f9985040-c506-11e7-88a6-6fe86a83bca1",
                                "name": "12\"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354153",
                                "price": 288000
                            }
                        ],
                        "id": "35589",
                        "created_at": "2017-11-09 11:31:08",
                        "multiple_choice": "0",
                        "updated_at": "2017-11-09 11:31:08",
                        "multiple_option": "0",
                        "max_choice": 1,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719"
                    },
                    {
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                        "min_choice": 1,
                        "mandatory": "1",
                        "name": "Pizza Size",
                        "option": [
                            {
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "trackable": 0,
                                "option_uuid": "08809140-2e5a-11e8-860c-5d835def37e1",
                                "name": "size 30",
                                "is_original": 0,
                                "type": "option",
                                "price": -10000,
                                "created_at": "2018-03-23 05:21:25",
                                "updated_at": "2018-03-23 05:21:25"
                            },
                            {
                                "updated_at": "2017-11-09 11:32:04",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "trackable": 0,
                                "option_uuid": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                                "name": "18 \"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354152",
                                "price": 398000,
                                "created_at": "2017-11-09 11:32:04"
                            },
                            {
                                "price": 288000,
                                "created_at": "2017-11-09 11:32:20",
                                "updated_at": "2017-11-09 11:32:20",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "option_uuid": "f9985040-c506-11e7-88a6-6fe86a83bca1",
                                "trackable": 0,
                                "name": "12\"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354153"
                            }
                        ],
                        "id": "35589",
                        "created_at": "2017-11-09 11:31:08",
                        "multiple_choice": "0",
                        "updated_at": "2017-11-09 11:31:08",
                        "multiple_option": "0",
                        "max_choice": 1
                    },
                    {
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0",
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time",
                        "option": [
                            {
                                "is_original": 1,
                                "type": "option",
                                "id": "354155",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "name": "Same time"
                            },
                            {
                                "trackab\n    le": 0,
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "name": "Table Share",
                                "is_original": 1,
                                "type": "option",
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077",
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:02",
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2",
                                "trackable": 0,
                                "name": "Hold",
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03",
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "type": "option",
                                "id": "354154",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:21",
                                "updated_at": "2017-11-09 11:32:21",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "name": "Anytime",
                                "is_original": 1
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09"
                    },
                    {
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time",
                        "option": [
                            {
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "trackable": 0,
                                "name": "Same time",
                                "is_original": 1,
                                "type": "option",
                                "id": "354155",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35"
                            },
                            {
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "trackable": 0,
                                "name": "Table Share",
                                "is_original": 1,
                                "type": "option",
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077",
                                "trackable": 0,
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:02",
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "name": "Hold",
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03",
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2"
                            },
                            {
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "trackable": 0,
                                "name": "Anytime",
                                "is_original": 1,
                                "type": "option",
                                "id": "354154",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:21",
                                "updated_at": "2017-11-09 11:32:21"
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09",
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0"
                    },
                    {
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time",
                        "option": [
                            {
                                "trackable": 0,
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "name": "Same time",
                                "is_original": 1,
                                "type": "option",
                                "id": "354155",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "is_original": 1,
                                "type": "option",
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "trackable": 0,
                                "name": "Table Share"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077",
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:02",
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2",
                                "trackable": 0,
                                "name": "Hold",
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03",
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "price": 0,
                                "created_at": "2017-11-09 11:32:2\n    1",
                                "updated_at": "2017-11-09 11:32:21",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "name": "Anytime",
                                "is_original": 1,
                                "type": "option",
                                "id": "354154"
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09",
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0",
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719"
                    },
                    {
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time",
                        "option": [
                            {
                                "type": "option",
                                "id": "354155",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "name": "Same time",
                                "is_original": 1
                            },
                            {
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "name": "Table Share",
                                "is_original": 1,
                                "type": "option"
                            },
                            {
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:02",
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077"
                            },
                            {
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03",
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2",
                                "trackable": 0,
                                "name": "Hold"
                            },
                            {
                                "updated_at": "2017-11-09 11:32:21",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "trackable": 0,
                                "name": "Anytime",
                                "is_original": 1,
                                "type": "option",
                                "id": "354154",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:21"
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09",
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0"
                    },
                    {
                        "option": [
                            {
                                "option_uuid": "02845080-c507-11e7-a7e3-ff33f1ea9e91",
                                "trackable": 0,
                                "name": "Same time",
                                "is_original": 1,
                                "type": "option",
                                "id": "354155",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            },
                            {
                                "name": "Table Share",
                                "is_original": 1,
                                "type": "option",
                                "id": "354156",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:35",
                                "updated_at": "2017-11-09 11:32:35",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "02a5b600-c507-11e7-820a-0b731a229780",
                                "trackable": 0
                            },
                            {
                                "created_at": "2017-11-09 11:33:02",
                                "updated_at": "2017-11-09 11:33:02",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "trackable": 0,
                                "option_uuid": "12baf4d0-c507-11e7-9291-8d6c54a9d077",
                                "name": "Wait for fire",
                                "is_original": 1,
                                "type": "option",
                                "id": "354157",
                                "price": 0
                            },
                            {
                                "is_original": 1,
                                "type": "option",
                                "id": "354158",
                                "price": 0,
                                "created_at": "2017-11-09 11:33:03",
                                "updated_at": "2017-11-09 11:33:03",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                                "option_uuid": "13147b40-c507-11e7-890b-c987bd73c9d2",
                                "trackable": 0,
                                "name": "Hold"
                            },
                            {
                                "trackable": 0,
                                "option_uuid": "f9faa150-c506-11e7-a671-33bd2e261084",
                                "name": "Anytime",
                                "is_original": 1,
                                "type": "option",
                                "id": "354154",
                                "price": 0,
                                "created_at": "2017-11-09 11:32:21",
                                "updated_at": "2017-11-09 11:32:21",
                                "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195"
                            }
                        ],
                        "id": "35590",
                        "created_at": "2017-11-09 11:31:09",
                        "multiple_choice": "0",
                        "updated_at": "2018-03-23 05:19:53",
                        "multiple_option": "0",
                        "max_choice": 5,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cf36f690-c506-11e7-ad67-070312136195",
                        "min_choice": 0,
                        "mandatory": "0",
                        "name": "Time"
                    },
                    {
                        "multiple_option": "0",
                        "max_choice": 1,
                        "is_original": 0,
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                        "min_choice": 1,
                        "mandatory": "1",
                        "name": "Pizza Size",
                        "option": [
                            {
                                "price": -10000,
                                "c\n    reated_at": "2018-03-23 05:21:25",
                                "updated_at": "2018-03-23 05:21:25",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "option_uuid": "08809140-2e5a-11e8-860c-5d835def37e1",
                                "trackable": 0,
                                "name": "size 30",
                                "is_original": 0,
                                "type": "option"
                            },
                            {
                                "id": "354152",
                                "price": 398000,
                                "created_at": "2017-11-09 11:32:04",
                                "updated_at": "2017-11-09 11:32:04",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "option_uuid": "f04a1500-c506-11e7-98b6-dd035c35d0cc",
                                "trackable": 0,
                                "name": "18 \"",
                                "is_original": 1,
                                "type": "option"
                            },
                            {
                                "updated_at": "2017-11-09 11:32:20",
                                "opt_set_uuid": "cea86fe0-c506-11e7-b87c-1f1cc4c618d7",
                                "trackable": 0,
                                "option_uuid": "f9985040-c506-11e7-88a6-6fe86a83bca1",
                                "name": "12\"",
                                "is_original": 1,
                                "type": "option",
                                "id": "354153",
                                "price": 288000,
                                "created_at": "2017-11-09 11:32:20"
                            }
                        ],
                        "id": "35589",
                        "created_at": "2017-11-09 11:31:08",
                        "multiple_choice": "0",
                        "updated_at": "2017-11-09 11:31:08"
                    }
                ],
                "taxes": [
                    {
                        "name": "phuc",
                        "all_categories": 1,
                        "value": 21,
                        "tax_type": 1,
                        "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 672890.82,
                        "cat_taxes": [],
                        "value_type": 0,
                        "cumulative": 1,
                        "default": 1,
                        "selected": true,
                        "translations": [
                            {
                                "id": 295,
                                "created_at": "2018-05-02 04:43:43",
                                "name": "phuc",
                                "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                                "updated_at": "2018-05-02 04:43:43"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1
                    },
                    {
                        "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 0,
                        "cat_taxes": [
                            {
                                "is_tax_set": 0,
                                "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                            }
                        ],
                        "value_type": 1,
                        "cumulative": 1,
                        "default": 0,
                        "selected": true,
                        "translations": [
                            {
                                "id": 314,
                                "created_at": "2018-05-04 07:50:31",
                                "name": "1223123",
                                "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                                "updated_at": "2018-05-04 07:50:31"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1,
                        "name": "1223123",
                        "all_categories": 0,
                        "value": 11,
                        "tax_type": 1
                    }
                ],
                "discount": [
                    {
                        "name": "phuc",
                        "all_categories": 1,
                        "value": 21,
                        "tax_type": 1,
                        "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 672890.82,
                        "cat_taxes": [],
                        "value_type": 0,
                        "cumulative": 1,
                        "default": 1,
                        "selected": true,
                        "translations": [
                            {
                                "id": 295,
                                "created_at": "2018-05-02 04:43:43",
                                "name": "phuc",
                                "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                                "updated_at": "2018-05-02 04:43:43"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1
                    },
                    {
                        "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                        "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                        "amount": 0,
                        "cat_taxes": [
                            {
                                "is_tax_set": 0,
                                "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                            }
                        ],
                        "value_type": 0,
                        "cumulative": 0,
                        "default": 0,
                        "selected": true,
                        "translations": [
                            {
                                "id": 314,
                                "created_at": "2018-05-04 07:50:31",
                                "name": "1223123",
                                "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                                "updated_at": "2018-05-04 07:50:31"
                            }
                        ],
                        "subAmount": 0,
                        "active": 1,
                        "name": "1223123",
                        "all_categories": 0,
                        "value": 11,
                        "tax_type": 1
                    }
                ]
            }
        ],
        "order": {
            "request_time": 0,
            "env": "qa",
            "transaction_id": "20180516042030000000",
            "total_discount": 0,
            "price": 3204242,
            "qty": 6,
            "delivery_fee": 0,
            "order_type": 1,
            "discounts": null,
            "source": 0,
            "total_tax": 672890.82,
            "subtotal": 3204242,
            "status": 1,
            "total": 3877132.82,
            "delivery_time": 0,
            "order_number": 93,
            "is_supplier": 0,
            "uuid": "f4397c70-58bf-11e8-89b2-1f112ceff90c",
            "created_at": "2018-05-16 04:16:49",
            "taxes": [
                {
                    "name": "phuc",
                    "all_categories": 1,
                    "value": 21,
                    "tax_type": 1,
                    "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                    "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                    "amount": 672890.82,
                    "cat_taxes": [],
                    "value_type": 0,
                    "cumulative": 1,
                    "default": 1,
                    "selected": true,
                    "translations": [
                        {
                            "id": 295,
                            "created_at": "2018-05-02 04:43:43",
                            "name": "phuc",
                            "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                            "updated_at": "2018-05-02 04:43:43"
                        }
                    ],
                    "subAmount": 0,
                    "active": 1
                },
                {
                    "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                    "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                    "amount": 0,
                    "cat_taxes": [
                        {
                            "is_tax_set": 0,
                            "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                        }
                    ],
                    "value_type": 1,
                    "cumulative": 1,
                    "default": 0,
                    "selected": true,
                    "translations": [
                        {
                            "id": 314,
                            "created_at": "2018-05-04 07:50:31",
                            "name": "1223123",
                            "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                            "updated_at": "2018-05-04 07:50:31"
                        }
                    ],
                    "subAmount": 0,
                    "active": 1,
                    "name": "1223123",
                    "all_categories": 0,
                    "value": 11,
                    "tax_type": 1
                }
            ],
            "discount": [
                {
                    "name": "phuc",
                    "all_categories": 1,
                    "value": 21,
                    "tax_type": 1,
                    "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                    "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                    "amount": 672890.82,
                    "cat_taxes": [],
                    "value_type": 0,
                    "cumulative": 1,
                    "default": 1,
                    "selected": true,
                    "translations": [
                        {
                            "id": 295,
                            "created_at": "2018-05-02 04:43:43",
                            "name": "phuc",
                            "tax_uuid": "64c569e0-4dc3-11e8-9af5-fb74e9d63127",
                            "updated_at": "2018-05-02 04:43:43"
                        }
                    ],
                    "subAmount": 0,
                    "active": 1
                },
                {
                    "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                    "outlet_uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
                    "amount": 0,
                    "cat_taxes": [
                        {
                            "is_tax_set": 0,
                            "category_uuid": "87581b80-c439-11e7-bd77-27fabda24dbe"
                        }
                    ],
                    "value_type": 0,
                    "cumulative": 0,
                    "default": 0,
                    "selected": true,
                    "translations": [
                        {
                            "id": 314,
                            "created_at": "2018-05-04 07:50:31",
                            "name": "1223123",
                            "tax_uuid": "d1ab8780-4f6f-11e8-bc36-6b0e25c91d93",
                            "updated_at": "2018-05-04 07:50:31"
                        }
                    ],
                    "subAmount": 0,
                    "active": 1,
                    "name": "1223123",
                    "all_categories": 0,
                    "value": 11,
                    "tax_type": 1
                }
            ],
            "updated_at": "2018-05-16 04:20:30",
            "note": null
        },
        "outlet": {
            "name": "Pizza bella",
            "geo_location": {
                "lat": 21.0302079,
                "long": 105.8126939
            },
            "currency": {
                "code": "VND",
                "decimal_digits": 0,
                "symbol_position": 1,
                "symbol": "₫",
                "rounding": 0,
                "name": "Vietnamese Dong",
                "symbol_native": "₫",
                "name_plural": "Vietnamese dong"
            },
            "uuid": "6c7cc550-c06c-11e7-9cc0-6791dae2a719",
            "hotel": {
                "env": "qa",
                "id": 323
            },
            "phone": "1688478526",
            "time_zone": null,
            "code": "27dsNrrJQE",
            "address": "506 Kim Mã, Ngọc Khánh, Ba Đình, Hà Nội, Vietnam",
            "translations": {
                "en": {
                    "slug": "pizza-bella",
                    "name": "Pizza bella"
                },
                "vi": {
                    "slug": "so-5-quang-trung",
                    "name": "So 5 quang trung"
                }
            }
        }
    },
    "error": false,
    "message": {
        "general": {
            "message": "operation success",
            "code": "operation_success"
        }
    }
}'));
var_dump($calculate->calculateOrderPrice($order));
var_dump("calculation Function Tests With required key fields");
$order=json_encode(json_decode('{
  "data": {
    "items": [
      {
        "taxes": [
          {
            "value": 21,
            "amount": 672890.82,
            "value_type": 0,
            "cumulative": 1,
            "subAmount": 0
          },
          {
            "amount": 0,
            "value_type": 1,
            "cumulative": 1,
            "subAmount": 0,
            "value": 11
          }
        ],
        "discount": [
          {
            "value": 21,
            "amount": 672890.82,
            "value_type": 0,
            "cumulative": 1,
            "subAmount": 0
          },
          {
            "amount": 0,
            "value_type": 0,
            "cumulative": 0,
            "subAmount": 0,
            "value": 11
          }
        ],
        "amount": 242,
        "total_discount": 0,
        "price": 60.5,
        "qty": 4,
        "pretax_price": 60.5,
        "options": {
          "breakdown": [],
          "total": 0
        },
        "total_tax": 50.82,
        "subtotal": 242,
        "total": 292.82
      },
      {
        "amount": 3204000,
        "total_discount": 0,
        "price": 10000,
        "qty": 2,
        "pretax_price": 10000,
        "options": {
          "breakdown": [
            {
              "price": 398000
            },
            {
              "price": 398000
            },
            {
              "price": 398000
            },
            {
              "price": 398000
            }
          ],
          "total": 0
        },
        "total_tax": 672840,
        "subtotal": 3204000,
        "total": 3876840,
        "taxes": [
          {
            "value": 21,
            "amount": 672890.82,
            "value_type": 0,
            "cumulative": 1,
            "subAmount": 0
          },
          {
            "amount": 0,
            "value_type": 1,
            "cumulative": 1,
            "subAmount": 0,
            "value": 11
          }
        ],
        "discount": [
          {
            "value": 21,
            "amount": 672890.82,
            "value_type": 0,
            "cumulative": 1,
            "subAmount": 0
          },
          {
            "amount": 0,
            "value_type": 0,
            "cumulative": 0,
            "subAmount": 0,
            "value": 11
          }
        ]
      }
    ],
    "order": {
      "total_discount": 0,
      "price": 3204242,
      "qty": 6,
      "delivery_fee": 0,
      "total_tax": 672890.82,
      "subtotal": 3204242,
      "total": 3877132.82
    }
  }
}'));
var_dump($calculate->calculateOrderPrice($order));die;

?>
