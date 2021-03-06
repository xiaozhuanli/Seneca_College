// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 1.0
// Date				2018/04/08
// Author			Jihyun Yoon
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018/04/08			File Made
/////////////////////////////////////////////////////////////////

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"
#include <iostream>

namespace AMA {
	const unsigned int max_sku_length = 7;
	const unsigned int max_unit_length = 10;
	const unsigned int max_name_length = 75;
	const double CUR_TAX = 0.13;
	class Product
	{
		char _prdtType;
		char _prdtSku[max_sku_length + 1];
		char _prdtUnitDesc[max_unit_length + 1];
		char* _prdtName;
		int _prdtQtyH;
		int _prdtQtyN;
		double _prdtUnitPrc;
		bool _taxable;
		ErrorState _prdtErrSt;
	protected:
		void name(const char* name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* errMsg);
		bool isClear() const;
	public:
		Product(char prdtType = 'N');
		Product(const char* sku, const char* prdtName, const char* prdtUnit, int prdtQtyH = 0, bool taxable = true, double prdtPrc = 0, int prdtQtyN = 0);
		Product(const Product& copyProduct);
		Product& operator=(const Product& copyProduct);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int unitNo);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* sku) const;
		bool operator>(const Product& product) const;
		int operator+=(int unitNo);
	};
	std::ostream& operator<<(std::ostream& os, const Product& product);
	std::istream& operator>>(std::istream& is, Product& product);
	double operator+=(double& add, const Product& product);

}

#endif // !AMA_PRODUCT_H
