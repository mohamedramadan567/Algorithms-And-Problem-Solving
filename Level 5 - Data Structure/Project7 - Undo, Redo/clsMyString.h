#pragma once
#include <iostream>
#include<stack>
#include"clsMyStackArr.h"
class clsMyString: public clsMyStackArr<string>
{
	string _Value;
	stack <string> _Undo;
	stack <string> _Redo;
	/*clsMyStackArr <string> _MyStack;
	clsMyStackArr <string> _MyStack2;*/
public:
	void SetValue(string Value)
	{
		_Undo.push(_Value);
		_Value = Value;
		/*_Value = Value;
		_MyStack.push(Value);*/
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
		/*_MyStack2.push(_MyStack.Top());
		_MyStack.pop();
		if (_MyStack.Size())
		{
			_Value = _MyStack.Top();
		}
		else
		{
			_Value = "";
		}*/
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
		/*if(_MyStack2.Size())
		{
			_MyStack.push(_MyStack2.Top());
			_Value = _MyStack2.Top();
			_MyStack2.pop();
		}*/
		
	}

};

