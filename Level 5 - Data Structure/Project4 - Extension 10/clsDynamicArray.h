#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;	
	T* _TempArray;
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

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; ++i)
			_TempArray[i] = OrginalArray[i];

		delete[] OrginalArray;
		
		_Size = NewSize;

		OrginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		if(Index >= 0 && Index < _Size)
			return OrginalArray[Index];

	}

	void Reverse()
	{
		_TempArray = new T[_Size];
		for (int i = 0, j = _Size - 1; i < _Size, j >= 0; i++, j--)
			_TempArray[i] = OrginalArray[j];

		delete[] OrginalArray;
		OrginalArray = _TempArray;
	}

	void Clear()
	{
		delete[] OrginalArray;
		_Size = 0;
		OrginalArray = new T[_Size];
	}

	bool DeleteItemAt(int Index)
	{
		if (Index < 0 || Index >= _Size)
			return false;

		_TempArray = new T[_Size - 1];
		/*short flag = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (i == Index)
			{
				flag = 1;
				continue;
			}

			if(flag == 1)
				_TempArray[i - flag] = OrginalArray[i];
			else 
				_TempArray[i + flag] = OrginalArray[i];
		}*/

		//another sol
		
		//copy all items before index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OrginalArray[i];
		}

		//copy all items after index
		for (int i = Index + 1; i < _Size; i++)
		{
			_TempArray[i - 1] = OrginalArray[i];
		}
		delete[] OrginalArray;
		OrginalArray = _TempArray;

		_Size--;

		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OrginalArray[i] == Value)
				return i;
		}

		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index == -1) return false;

		DeleteItemAt(Index);
		return true;
	}

	bool InsertAt(int Index, T NewValue)
	{
		if (Index < 0 || Index > _Size)
			return false;
		_Size++;

		_TempArray = new T[_Size];

		//copy all items before index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OrginalArray[i];
		}

		_TempArray[Index] = NewValue;

		//copy all items after index
		for (int i = Index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OrginalArray[i];
		}

		delete[] OrginalArray;
		OrginalArray = _TempArray;
		return true;
	}
};

