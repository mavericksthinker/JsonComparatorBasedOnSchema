//
// Created by mavericks on 5/25/18.
//

#ifndef SHAREDLIB_LIBRARY_H
#define SHAREDLIB_LIBRARY_H

#include "rapidjson/document.h"
#include <regex>
#include <string>
#include "rapidjson/pointer.h"
#include "rapidjson/writer.h"



using namespace rapidjson;
class Validation {
public:
    static bool checkEmailValid(std::string );
    static bool checkPhoneValid(std::string );
    static bool isEqualItem(const std::string &, const std::string &, const std::string &);
    static bool getPath(const Value &, const Value &, const Value &, const Value &, const Value &, const Pointer &);
    static std::string getPaths(std::string );
    static std::string findValue(const Value &, std::string );
};

class Aclpermission{
public:
    static bool checkPermission(std::string , const std::string &);


};

class calculation{

public:
    static std::string calculateOrderPrice(const std::string &);
    static void getData(const Value& ,const Value& );
    static void getItems(const Value& , const Value& , const Value& );
    static long double getDiscount(long double , const Value &,double );
    static long double getTaxes(long double , const Value &,double );
    static long double calculateTax(long double , const Value& ,double );
    static std::string calculationOfItems( const Value& );
    static long double getOptionPrices(const Value& );

};

#endif //SHAREDLIB_LIBRARY_H
