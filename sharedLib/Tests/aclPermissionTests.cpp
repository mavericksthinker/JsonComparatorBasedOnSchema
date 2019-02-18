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
    class ClassDeclaration:public testing::Test{
    public:
        Aclpermission aclpermission;
        ClassDeclaration(){
            aclpermission;

        }
    };
}



TEST_F(ClassDeclaration,Checking_of_permission_for_id_acl_pos_transaction_VIEW_TRANSACTION_that_exists_in_the_permission_list){

    bool a=Aclpermission::checkPermission("acl.pos.transaction.VIEW_TRANSACTION","[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\", \"acl.admin.outlet.MANAGE_OUTLET_SETTING\", \"acl.admin.location.MANAGE_LOCATION\", \"acl.admin.dashboard.VIEW_DASHBOARD\", \"acl.admin.information.VIEW_INFORMATION\", \"acl.admin.information.MANAGE_INFORMATION\", \"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\", \"acl.admin.tax.VIEW_TAX\", \"acl.admin.tax.MANAGE_TAX\", \"acl.admin.discount.VIEW_DISCOUNT\", \"acl.admin.discount.MANAGE_DISCOUNT\", \"acl.admin.catalogue.VIEW_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATEGORY\", \"acl.admin.catalogue.MANAGE_ITEM\", \"acl.admin.catalogue.MANAGE_OPTION\", \"acl.admin.catalogue.MANAGE_OPTION_SET\", \"acl.admin.table.VIEW_TABLE\", \"acl.admin.table.MANAGE_TABLE\", \"acl.admin.staff.VIEW_STAFF\", \"acl.admin.staff.MANAGE_STAFF\", \"acl.admin.role.MANAGE_ROLE\", \"acl.admin.settings.ACCESS_CUSTOMER\", \"acl.admin.settings.ACCESS_DEVICES\", \"acl.admin.settings.ACCESS_CONFIGURATION\", \"acl.admin.settings.ACCESS_LOYALTY\", \"acl.admin.settings.ACCESS_THIRD_PARTY_INTEGRATION\", \"acl.admin.settings.ACCESS_PAYMENT\", \"acl.admin.settings.ACCESS_ONLINE_ORDERING\", \"acl.admin.accountability.VIEW_ACCOUNTABILITY\", \"acl.pos.login.LOGIN\", \"acl.pos.catalogue.MANAGE_CATALOGUE\", \"acl.pos.order.MANAGE_TAX\", \"acl.pos.order.MANAGE_DISCOUNT\", \"acl.pos.order.ADD_ORDER\", \"acl.pos.order.UPDATE_ORDER\", \"acl.pos.order.CANCEL_ORDER\", \"acl.pos.transaction.REFUND_ORDER\", \"acl.pos.order.MANAGE_OPEN_ITEM\", \"acl.pos.order.ADD_REMARK\", \"acl.pos.payment.PAY_BY_CASH\", \"acl.pos.payment.PAY_BY_CARD\", \"acl.pos.transaction.VIEW_TRANSACTION\", \"acl.pos.transaction.CLOSE_CASH\", \"acl.pos.printer.VIEW_PRINTER_SETTINGS\", \"acl.pos.printer.MANAGE_PRINTER_SETTINGS\", \"acl.pos.supervisor.AUTHORIZE_ACTION\", \"acl.pos.customer.DEPOSIT\", \"acl.pos.table.MANAGE_TABLE\", \"acl.pos.supplier.VIEW_SUPPLIER\", \"acl.pos.supplier.MANAGE_SUPPLIER_ORDER\", \"acl.pos.timelog.TIME_LOGGING\"]");
    bool expected=true;
    ASSERT_EQ(expected,a);
    cout<<"Permission Granted ,expected:"<<expected<<"passed with true"<<endl<<endl;
}


TEST_F(ClassDeclaration,Checking_of_permission_for_id_acl_admin_report_VIEW_that_doesnt_exists_in_the_permission_list){
    bool a=Aclpermission::checkPermission("acl.admin.report.VIEW","{	\"permissions\": {		\"Permission1\": [	[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\"],		\"Permission2\": [			\"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\"]	}}");
    bool expected= false;
    ASSERT_EQ(expected,a);
    cout<<"Permission not Granted,expected:"<<expected<<"passed with false"<<endl<<endl;
}

TEST_F(ClassDeclaration,Checking_of_permission_for_id_admin_outlet_MANAGE_OUTLET_that_exists_in_the_permission_list){

    bool a=Aclpermission::checkPermission("acl.admin.outlet.MANAGE_OUTLET","[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\", \"acl.admin.outlet.MANAGE_OUTLET_SETTING\", \"acl.admin.location.MANAGE_LOCATION\", \"acl.admin.dashboard.VIEW_DASHBOARD\", \"acl.admin.information.VIEW_INFORMATION\", \"acl.admin.information.MANAGE_INFORMATION\", \"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\", \"acl.admin.tax.VIEW_TAX\", \"acl.admin.tax.MANAGE_TAX\", \"acl.admin.discount.VIEW_DISCOUNT\", \"acl.admin.discount.MANAGE_DISCOUNT\", \"acl.admin.catalogue.VIEW_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATEGORY\", \"acl.admin.catalogue.MANAGE_ITEM\", \"acl.admin.catalogue.MANAGE_OPTION\", \"acl.admin.catalogue.MANAGE_OPTION_SET\", \"acl.admin.table.VIEW_TABLE\", \"acl.admin.table.MANAGE_TABLE\", \"acl.admin.staff.VIEW_STAFF\", \"acl.admin.staff.MANAGE_STAFF\", \"acl.admin.role.MANAGE_ROLE\", \"acl.admin.settings.ACCESS_CUSTOMER\", \"acl.admin.settings.ACCESS_DEVICES\", \"acl.admin.settings.ACCESS_CONFIGURATION\", \"acl.admin.settings.ACCESS_LOYALTY\", \"acl.admin.settings.ACCESS_THIRD_PARTY_INTEGRATION\", \"acl.admin.settings.ACCESS_PAYMENT\", \"acl.admin.settings.ACCESS_ONLINE_ORDERING\", \"acl.admin.accountability.VIEW_ACCOUNTABILITY\", \"acl.pos.login.LOGIN\", \"acl.pos.catalogue.MANAGE_CATALOGUE\", \"acl.pos.order.MANAGE_TAX\", \"acl.pos.order.MANAGE_DISCOUNT\", \"acl.pos.order.ADD_ORDER\", \"acl.pos.order.UPDATE_ORDER\", \"acl.pos.order.CANCEL_ORDER\", \"acl.pos.transaction.REFUND_ORDER\", \"acl.pos.order.MANAGE_OPEN_ITEM\", \"acl.pos.order.ADD_REMARK\", \"acl.pos.payment.PAY_BY_CASH\", \"acl.pos.payment.PAY_BY_CARD\", \"acl.pos.transaction.VIEW_TRANSACTION\", \"acl.pos.transaction.CLOSE_CASH\", \"acl.pos.printer.VIEW_PRINTER_SETTINGS\", \"acl.pos.printer.MANAGE_PRINTER_SETTINGS\", \"acl.pos.supervisor.AUTHORIZE_ACTION\", \"acl.pos.customer.DEPOSIT\", \"acl.pos.table.MANAGE_TABLE\", \"acl.pos.supplier.VIEW_SUPPLIER\", \"acl.pos.supplier.MANAGE_SUPPLIER_ORDER\", \"acl.pos.timelog.TIME_LOGGING\"]");
    bool expected=true;
    ASSERT_EQ(expected,a);
    cout<<"Permission Granted ,expected:"<<expected<<"passed with true"<<endl<<endl;
}

TEST_F(ClassDeclaration,Checking_of_permission_for_id_admin_that_exists_in_the_permission_list_in_the_nested_List){

    bool a=Aclpermission::checkPermission("acl.admin","{	\"permissions\": {		\"Permission1\": [	[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\"],		\"Permission2\": [			\"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\"]	}}");
    bool expected= false;
    ASSERT_EQ(expected,a);
    cout<<"Permission not Granted,expected:"<<expected<<"passed with false"<<endl<<endl;
}

TEST_F(ClassDeclaration,Checking_of_permission_for_id_admin_login_LOGIN_that_exists_in_the_permission_list){

    bool a=Aclpermission::checkPermission("acl.admin.login.LOGIN","[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\", \"acl.admin.outlet.MANAGE_OUTLET_SETTING\", \"acl.admin.location.MANAGE_LOCATION\", \"acl.admin.dashboard.VIEW_DASHBOARD\", \"acl.admin.information.VIEW_INFORMATION\", \"acl.admin.information.MANAGE_INFORMATION\", \"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\", \"acl.admin.tax.VIEW_TAX\", \"acl.admin.tax.MANAGE_TAX\", \"acl.admin.discount.VIEW_DISCOUNT\", \"acl.admin.discount.MANAGE_DISCOUNT\", \"acl.admin.catalogue.VIEW_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATALOGUE\", \"acl.admin.catalogue.MANAGE_CATEGORY\", \"acl.admin.catalogue.MANAGE_ITEM\", \"acl.admin.catalogue.MANAGE_OPTION\", \"acl.admin.catalogue.MANAGE_OPTION_SET\", \"acl.admin.table.VIEW_TABLE\", \"acl.admin.table.MANAGE_TABLE\", \"acl.admin.staff.VIEW_STAFF\", \"acl.admin.staff.MANAGE_STAFF\", \"acl.admin.role.MANAGE_ROLE\", \"acl.admin.settings.ACCESS_CUSTOMER\", \"acl.admin.settings.ACCESS_DEVICES\", \"acl.admin.settings.ACCESS_CONFIGURATION\", \"acl.admin.settings.ACCESS_LOYALTY\", \"acl.admin.settings.ACCESS_THIRD_PARTY_INTEGRATION\", \"acl.admin.settings.ACCESS_PAYMENT\", \"acl.admin.settings.ACCESS_ONLINE_ORDERING\", \"acl.admin.accountability.VIEW_ACCOUNTABILITY\", \"acl.pos.login.LOGIN\", \"acl.pos.catalogue.MANAGE_CATALOGUE\", \"acl.pos.order.MANAGE_TAX\", \"acl.pos.order.MANAGE_DISCOUNT\", \"acl.pos.order.ADD_ORDER\", \"acl.pos.order.UPDATE_ORDER\", \"acl.pos.order.CANCEL_ORDER\", \"acl.pos.transaction.REFUND_ORDER\", \"acl.pos.order.MANAGE_OPEN_ITEM\", \"acl.pos.order.ADD_REMARK\", \"acl.pos.payment.PAY_BY_CASH\", \"acl.pos.payment.PAY_BY_CARD\", \"acl.pos.transaction.VIEW_TRANSACTION\", \"acl.pos.transaction.CLOSE_CASH\", \"acl.pos.printer.VIEW_PRINTER_SETTINGS\", \"acl.pos.printer.MANAGE_PRINTER_SETTINGS\", \"acl.pos.supervisor.AUTHORIZE_ACTION\", \"acl.pos.customer.DEPOSIT\", \"acl.pos.table.MANAGE_TABLE\", \"acl.pos.supplier.VIEW_SUPPLIER\", \"acl.pos.supplier.MANAGE_SUPPLIER_ORDER\", \"acl.pos.timelog.TIME_LOGGING\"]");
    bool expected=true;
    ASSERT_EQ(expected,a);
    cout<<"Permission Granted ,expected:"<<expected<<"passed with true"<<endl<<endl;
}

TEST_F(ClassDeclaration,Checking_of_permission_for_id_admin_access_that__exists_in_the_permission_list_in_the_nested_List){

    bool a=Aclpermission::checkPermission("acl.admin.access","{	\"permissions\": {		\"Permission1\": [	[\"acl.admin.login.LOGIN\", \"acl.admin.report.VIEW_ORDER\", \"acl.admin.report.VIEW_PAYMENT\", \"acl.admin.outlet.MANAGE_OUTLET\"],		\"Permission2\": [			\"acl.admin.inventory.VIEW_CUSTOMER\", \"acl.admin.inventory.MANAGE_CUSTOMER\", \"acl.admin.inventory.VIEW_INVENTORY\", \"acl.admin.inventory.MANAGE_INVENTORY\"]	}}");
    bool expected= false;
    ASSERT_EQ(expected,a);
    cout<<"Permission not Granted,expected:"<<expected<<"passed with false"<<endl<<endl;
}




