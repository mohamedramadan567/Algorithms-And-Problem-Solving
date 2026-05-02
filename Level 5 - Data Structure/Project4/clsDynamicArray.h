#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;	
public:
	T* OrginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;
		
		_Size = Size;

		OrginalArray = new T[_Size];	
	}

	~clsDynamicArray()
	{
		delete[] OrginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
			return false;

		OrginalArray[Index] = Value;
		return true;
	}

	bool IsEmpty()
	{
		return !_Size;
		//return (_Size == 0 ? true : false);
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OrginalArray[i] << " ";
		}
		cout << endl;
	}

	bool Resize(int NewSize)
	{
		if (NewSize < 0)
			return 0;
		_Size = NewSize;

	}

};

