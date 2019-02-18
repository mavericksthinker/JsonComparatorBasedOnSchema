//
// Created by mavericks on 5/28/18.
//


#include "library.h"
using namespace std;

//When Provided with an order in form of json string , it calculates and provides the total calculation for the entire order

 string calculation::calculateOrderPrice(const string &order){

    Document orderJson;
    orderJson.Parse(order.c_str());


    const Value& data=orderJson["data"];

    getData(orderJson,data);

     StringBuffer orders;
     Writer<StringBuffer> writer1(orders);
     orderJson.Accept(writer1);

    return orders.GetString();
}

//To get the item and order json from the data of the orderJson

void calculation::getData(const Value& orderJson,const Value& data){

    const Value& items=data["items"];
    const Value& order=data["order"];
    getItems(orderJson,items,order);


}

//To operate on the items and the order json separately

void calculation::getItems(const Value& finalOrder, const Value& item, const Value& order){

    double amountOfAllItems=0;
    double subTotalAllItems=0;
    double totalDiscountOfAllTheItems=0;
    double totalTaxOfAllTheItems=0;
    double totalAmountOfAllTheItems=0;
    double totalQuantityOfAllTheItems=0;

    //iterate inside the item array

    string outputOfTheOrder;
    for(SizeType itr=0;itr<item.Size();itr++){


       string itemsOutput=calculationOfItems(item[itr]);

        //Add the amount, subamount, tax ,discount, totalAmount

        assert(item[itr]["amount"].IsNumber());
        amountOfAllItems=amountOfAllItems+item[itr]["amount"].GetDouble();
        assert(item[itr]["subtotal"].IsNumber());
        subTotalAllItems=subTotalAllItems+item[itr]["subtotal"].GetDouble();
        assert(item[itr]["total_discount"].IsNumber());
        totalDiscountOfAllTheItems=totalDiscountOfAllTheItems+item[itr]["total_discount"].GetDouble();
        assert(item[itr]["total_tax"].IsNumber());
        totalTaxOfAllTheItems=totalTaxOfAllTheItems+item[itr]["total_tax"].GetDouble();

        totalQuantityOfAllTheItems=totalQuantityOfAllTheItems+item[itr]["qty"].GetInt();
        assert(item[itr]["total"].IsNumber());
        totalAmountOfAllTheItems=totalAmountOfAllTheItems+item[itr]["total"].GetDouble();

    }

    //Set the values for the order field (price =amount of all items, subtotal =subtotal of all the items,total discount of all the items,tax of all the amounts,

    const Value& orderAmount=order["price"];
    Value& orderAmounts= const_cast<Value &>(orderAmount);
    orderAmounts.SetDouble(amountOfAllItems);

    const Value& orderSubTotal=order["subtotal"];
    Value& orderSubTotals= const_cast<Value &>(orderSubTotal);
    orderSubTotals.SetDouble(subTotalAllItems);

    const Value& orderTotalDiscount=order["total_discount"];
    Value& orderTotalDiscounts= const_cast<Value &>(orderTotalDiscount);
    orderTotalDiscounts.SetDouble(totalDiscountOfAllTheItems);

    const Value& orderTotalTax=order["total_tax"];
    Value& orderTotalTaxes= const_cast<Value &>(orderTotalTax);
    orderTotalTaxes.SetDouble(totalTaxOfAllTheItems);

    const Value& orderTotalQuantity=order["qty"];
    Value& orderTotalQuantities= const_cast<Value &>(orderTotalQuantity);
    orderTotalQuantities.SetDouble(totalQuantityOfAllTheItems);

    assert(order["delivery_fee"].IsNumber());
    totalAmountOfAllTheItems=totalAmountOfAllTheItems+order["delivery_fee"].GetDouble();
    const Value& orderFinalAmount=order["total"];
    Value& orderTotalAmount= const_cast<Value &>(orderFinalAmount);
    orderTotalAmount.SetDouble(totalAmountOfAllTheItems);

}

//Calculate each Discount for an Item

 long double calculation::getDiscount(long double subTotalOfItem, const Value &discount,double qty) {

     long double discountAmount;

    if(discount["value_type"].GetInt()==0){

        //Calculate the Discount Amount

        double percent=(discount["value"].GetInt())*.01;
        discountAmount=subTotalOfItem*(percent);

        //Set the discount in amount and subAmount field for an Item

        const Value& itemDiscount=discount["amount"];
        Value& itemsDiscount= const_cast<Value &>(itemDiscount);
        itemsDiscount.SetDouble(discountAmount);
        const Value& eachItemDiscount=discount["subAmount"];
        Value& eachitemsDiscount= const_cast<Value &>(eachItemDiscount);
        eachitemsDiscount.SetDouble(discountAmount/qty);

        return discountAmount;

    }else{
        //Calculate the discount Amount
        assert(discount["value"].IsNumber());
        discountAmount=discount["value"].GetDouble();

        //Set the discount in amount and subAmount field for an Item

        const Value& itemDiscount=discount["amount"];
        Value& itemsDiscount= const_cast<Value &>(itemDiscount);
        itemsDiscount.SetDouble(discountAmount);
        const Value& eachItemDiscount=discount["subAmount"];
        Value& eachitemsDiscount= const_cast<Value &>(eachItemDiscount);
        eachitemsDiscount.SetDouble(discountAmount/qty);

        return discountAmount;
    }
}

//Calculate tax based on whether it is cumulative or not

 long double calculation::getTaxes(long double amount, const Value &taxes,double qty) {

    long double Tax=0;

    for(SizeType itr=0;itr<taxes.Size();itr++){

        const Value& tax=taxes[itr];
        if(tax["cumulative"].GetInt()==0){

            //Calculates the Non Cumulative Tax

            Tax=Tax+calculateTax(amount,tax,qty);


            //Calculation of tax when it is cumulative

        }else if(tax["cumulative"].GetInt()==1){

            Tax=Tax+calculateTax(amount,tax,qty);


            if(tax["value_type"].GetInt()==0) {
                double percent=tax["value"].GetInt()*.01;

                long double Taxes=amount*percent;


                amount = amount + Taxes;

            }else{
                tax["value"].IsNumber();
                amount =amount+tax["value"].GetDouble();

            }


        }
    }
    return Tax;
}

//Calculate each tax for an Item

 long double calculation::calculateTax(long double amount, const Value& tax,double qty){


    long double Taxes=0;
    if(tax["value_type"].GetInt()==0){

        double percent=tax["value"].GetInt()*.01;

        Taxes=amount*percent;

        //Setting up values for the tax in amout and subAmount

        const Value& itemTax=tax["amount"];
        Value& itemsTax= const_cast<Value &>(itemTax);
        itemsTax.SetDouble(Taxes);
        const Value& eachItemTax=tax["subAmount"];
        Value& eachitemsTax= const_cast<Value &>(eachItemTax);
        eachitemsTax.SetDouble(Taxes/qty);

    }else{
        assert(tax["value"].IsNumber());
        Taxes=tax["value"].GetDouble();

        //Setting up values for the tax in amout and subAmount

        const Value& itemTax=tax["amount"];
        Value& itemsTax= const_cast<Value &>(itemTax);
        itemsTax.SetDouble(Taxes);
        const Value& eachItemTax=tax["subAmount"];
        Value& eachitemsTax= const_cast<Value &>(eachItemTax);
        eachitemsTax.SetDouble(Taxes/qty);
    }
    return Taxes;
}

//Calculate the subAmount , Discount ,Amount , Taxes, Total per Item

string calculation:: calculationOfItems( const Value& item){

    assert(item["price"].IsNumber());
    double price=item["price"].GetDouble();
    assert(item["qty"].IsNumber());
    double quantity=item["qty"].GetDouble();
    const Value& optionsList=item["options"];
    const  Value& breakdown=optionsList["breakdown"];
    double optionTotal=0;

    //iterator to get the price of the options
    if(!breakdown.IsNull()) {
        for (SizeType itr = 0; itr < breakdown.Size(); itr++) {

            optionTotal=optionTotal+getOptionPrices(breakdown[itr]);

        }
    }
    double subTotal=(price+optionTotal)*quantity;
    long double subAmount=subTotal;

    //Calculation of all the Discounts of an Item
    const Value& discounts=item["discount"];
    const Value& taxes=item["taxes"];

    double totalDiscount=0;

    //If Discount array is Null it refers to totalDiscount for the item is 0 ,if not it calculates the discount from getDiscount() and calculateTax()

    if(!discounts.IsNull()) {
        for (SizeType itr = 0; itr < discounts.Size(); itr++) {

            double discountamountts= getDiscount(subAmount, discounts[itr],quantity);

            totalDiscount = totalDiscount + discountamountts ;

            subAmount=subAmount-discountamountts;

        }
    }
    double amount=subTotal-totalDiscount;

    //Calculate all the taxes for an Item

    double totalTaxes=0;

    //If Tax array is Null then the total tax is considered as 0 ,if not it calculates the tax from getTaxes() and calculateTax()

    if(!taxes.IsNull()){

        totalTaxes=getTaxes(amount,taxes,quantity);

    }

    double totalAmount=amount+totalTaxes;


    //set the values(amount ,total discount, totaltax, pre-tax price,subtotal,totalAmount,option total) for each item

    const Value& amounts=item["amount"];
    Value& amountss= const_cast<Value &>(amounts);
    amountss.SetDouble(amount);

    const Value& total_Discounts=item["total_discount"];
    Value& totalDiscounts= const_cast<Value &>(total_Discounts);
    totalDiscounts.SetDouble(totalDiscount);

    const Value& pretax_price=item["pretax_price"];
    Value& pretax_prices= const_cast<Value &>(pretax_price);
    pretax_prices.SetDouble(price);

    const Value& total_tax=item["total_tax"];
    Value& total_Tax= const_cast<Value &>(total_tax);
    total_Tax.SetDouble(totalTaxes);

    const Value& sub_total=item["subtotal"];
    Value& sub_totals= const_cast<Value &>(sub_total);
    sub_totals.SetDouble(subTotal);

    const Value& total_Amount=item["total"];
    Value& total_Amounts= const_cast<Value &>(total_Amount);
    total_Amounts.SetDouble(totalAmount);

    const Value& total_Option_Price=item["options"]["total"];
    Value& total_Option_prices= const_cast<Value &>(total_Option_Price);
    total_Option_prices.SetDouble(optionTotal);

    //stringify the Item json basically done for unit test the function can be void

    StringBuffer items;
    Writer<StringBuffer> writer(items);
    item.Accept(writer);
    return items.GetString();
}

//Calculates the price of the optionItems If exists

 long double calculation::getOptionPrices(const Value& options){

    options["price"].IsNumber();
    long double optionTotal=options["price"].GetDouble();
    return optionTotal;
}