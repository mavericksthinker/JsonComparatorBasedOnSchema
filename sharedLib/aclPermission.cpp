//
// Created by mavericks on 5/25/18.
//

#include "library.h"

using namespace std;


bool Aclpermission:: checkPermission( string userID, const string &json) {

    Document permission;
    permission.Parse(json.c_str());
    if(permission.HasParseError()){
        return false;
    }
    bool match=false;

    StringBuffer string;
    Writer<StringBuffer> writer(string);
    permission.Accept(writer);

    if(permission.IsArray()) {
        for (SizeType itr = 0; itr < permission.Size(); itr++) {

            if (permission[itr].GetString() == userID) {

                match = true;
                break;
            }
        }
    }
    return match;

}
