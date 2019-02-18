//
// Created by mavericks on 5/25/18.
//

#include "library.h"

using namespace std;
using namespace rapidjson;

//Checks the validity of the email

bool Validation::checkEmailValid(string email) {

    const std::regex pattern  //pattern to check validity of Email
            ("^(?:(?:[^<>()\\[\\].,;:\\s@\"]+(?:\\.[^<>()\\[\\].,;:\\s@\"]+)*)|\".+\")@(?:(?:[^<>()\\[\\].,;:\\s@\"]+\\.)+[^<>()\\[\\].,;:\\s@\"]{2,})$");


    return std::regex_match(email, pattern);
}

//This function will check the validity of the phone number

bool Validation::checkPhoneValid(string phone) {
    bool a = false;
    //regex pattern to check the numbers
    const std::regex pattern("^[0-9\-\+\\s]{9,15}$");
    const std::regex pattern1("^[0-9\-\+]{9,15}$");
    const std::regex pattern2("[[:digit:]]{2}-[[:digit:]]{3}-[[:digit:]]{4}");
    const std::regex pattern3("\\([[:digit:]]{3}\\)[[:digit:]]{3}-[[:digit:]]{4}");
    const std::regex pattern4("[[:digit:]]{3}-[[:digit:]]{4}");
    const std::regex pattern5("[[:digit:]]{3}\\s[[:digit:]]{3}\\s[[:digit:]]{3}\\s[[:digit:]]{4}");
    if (std::regex_match(phone, pattern) || std::regex_match(phone, pattern1) || std::regex_match(phone, pattern2) ||
        std::regex_match(phone, pattern3) | std::regex_match(phone, pattern4) || std::regex_match(phone, pattern5)) {
        a = true;
    }
    return a;
}
//This function will check the item1 and item2 are equal based on the template(temp) keys

bool Validation::isEqualItem(const std::string &item1, const std::string &item2, const std::string &temp) {

    //parse the json string to Document type

    Document document1;
    document1.Parse(item1.c_str());
    Document document2;
    document2.Parse(item2.c_str());
    Document Template;
    Template.Parse(temp.c_str());
    if (document1.HasParseError()||document2.HasParseError()||Template.HasParseError()) {
        return false;
    }
    //Declared a pointer to hold the path of the keys in the template
    Pointer root;
    bool match = getPath(document1, document2, document1, document2, Template, root);//Sending the Item1,Item2,Template and a copy of the item1 and item2 with a pointer to hold the path
//Match will return the actual result
    return match;
}

bool
Validation::getPath(const Value &item1, const Value &item2, const Value &value1, const Value &value2, const Value &temp, const Pointer &parent) {
    bool match = true;
    //iterate through the template and retrive the entire path fo the final key
    if (temp.IsObject())
        for (Value::ConstMemberIterator itr = temp.MemberBegin();
             itr != temp.MemberEnd(); ++itr) {       //Iterate through the elements of the object type Json

            if (value1.HasMember(itr->name) && value2.HasMember(itr->name)) {
                match = getPath(item1, item2, value1[itr->name.GetString()], value2[itr->name.GetString()], itr->value,
                                parent.Append(itr->name.GetString()));

            } else {
                match = false;
                break;
            }

            if (match == 0) {
                break;
            }
        }
    else if (temp.IsArray()) {
        auto lengthOfTemp = temp.Size();
        auto lengthOfItem1 = value1.Size();
        auto lengthOfItem2 = value2.Size();

        //Iterator for the template array

        for (SizeType i = 0; i < lengthOfTemp; i++) {
            if (lengthOfTemp > lengthOfItem1 || lengthOfItem1 !=
                                                lengthOfItem2) {//If the length of Template is more than the item1 and If the length of Item 1 and item 2 are equal or not
                match = false;
                break;
            } else if (lengthOfTemp == lengthOfItem1) {
                match = getPath(item1, item2, value1[i], value2[i], temp[i], parent.Append(i));

                if (match == 0) {
                    break;
                }
            } else {
                //Iterate to make a copy of the template in the item1 and item 2 in the template to compare
                for (SizeType j = 0; j < lengthOfItem1;j++) {
                    match = getPath(item1, item2, value1[j], value2[j], temp[i], parent.Append(j));
                    if (match == 0) {
                        break;
                    }
                }
            }

        }
    } else {

        //A String Buffer to convert the path to a string
        StringBuffer sb;
        parent.Stringify(sb);
        //Reformats the path for convinience
        string path = getPaths(sb.GetString());
        //Pass the item1 json and get the respective value for the prescribed path
        string val = findValue(item1, path);
        //Pass the item2 json and get the respective value for the prescribed path
        string val1 = findValue(item2, path);
        //compare those two values for item1 and item2 respectively
        if (val != val1 || val == "Dont have the key in the json" || val1 == "Dont have the key in the json") {

            match = false;
            return match;

        }
    }

    return match;
}

//It adds a "/" to the path required for separating each part of the path

string Validation::getPaths(string path) {
    path = path.erase(0, 1);
    path = path + "/";
    return path;
}

// This function finds the value based on the path provided in the item1 and item2

string Validation::findValue(const Value &item, string path) {

    //stringify the item json sent

    StringBuffer itemAsString;
    Writer<StringBuffer> writer(itemAsString);
    item.Accept(writer);

    string delimiter = "/";

    string keys, paths, result;

    keys = path.substr(0, path.find(delimiter));


    if (path.length() > 1) {
        if (item.HasMember(keys.c_str())) {

            //element stores the Value of the prescribed key

            const Value &element = item[keys.c_str()];
            StringBuffer elementAsString;
            Writer<StringBuffer> writer2(elementAsString);
            element.Accept(writer2);

            //Erase the first key from the path

            paths = path.erase(0, keys.length() + 1);

            //To check the path length

            if (paths.length() > 1) {
                if (element.IsObject()) {

                    //Recursion to go to nested level

                    result = findValue(element, paths);
                } else if (element.IsArray()) {
                    string token = path.substr(0, path.find(delimiter));

                    //Converts the key to an Int format
                    int key = stoi(token);

                    paths = paths.erase(0, token.length() + 1);
                    if (element[key].IsArray() || element[key].IsObject()) {

                        //Recursion to go to nested level

                        result = findValue(element[key], paths);


                    } else {

                        //stores the array which doesnt has object or array inside it
                        StringBuffer valueOfArray;
                        Writer<StringBuffer> writer1(valueOfArray);
                        element.Accept(writer1);

                        //Returns the entire value of the array
                        return valueOfArray.GetString();
                    }
                }

            } else {

                //returns the value as string for the final key of the nested json

                return elementAsString.GetString();
            }
        } else {
            //If any json doesnt have a key specified in the path
            result = "Dont have the key in the json";
            return result;
        }
    } else {
        //returns the entire json as string to be compared if the template is null
        return itemAsString.GetString();
    }
    return result;
}