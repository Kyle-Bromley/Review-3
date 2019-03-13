#pragma once
#include "RowAray.h"
template<class T>
class Table {
protected:
	int szRow;
	int szCol;
	RowAray<T> **columns;
public:
	Table(unsigned int, unsigned int);
	Table(const Table<T> &);
	virtual ~Table();
	int getSzRow()const { return szRow; }
	int getSzCol()const { return szCol; }
	T getData(int, int)const;
	void setData(int, int, T);
	Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int r, unsigned int c)
{
	szRow = r;
	szCol = c;
	columns = new RowAray<T>*(new RowAray<T>(szRow*szCol));
}

template<class T>
Table<T>::Table(const Table<T>& cT)
{
	szRow = cT.getSzRow();
	szCol = cT.getSzCol();

	columns = cT.columns;
}

template<class T>
inline Table<T>::~Table()
{
}

template<class T>
inline T Table<T>::getData(int r, int c) const
{
	return (*records)->getData(r + c);
}

template<class T>
inline void Table<T>::setData(int r, int c, T data)
{
	columns[r][c] = data;
}

template<class T>
inline Table<T> Table<T>::operator+(const Table<T> &t)
{
	Table<T> *sT = new Table<T>(szRow, szCol);
	
	for (int i = 0; i < szRow(); i++) 
	{
		for (int j = 0; j < szCol(); j++)
		{
                    st->setData(i,j, t.getData(i,j) + getData(i,j));
		}
	}

	return *st;
}