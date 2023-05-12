#pragma once


template<typename type1, typename type2>
struct Pair
{

	type1 first;

	type2 second;

	void swap(Pair<type1, type2> pair)
	{
		type1 field1 = pair.first;
		pair.first = this->first;
		this->first = field1;
		type2 field2 = pair.second;
		pair.second = this->second;
		this->second = field2;
	}

	void operator=(const Pair& pair)
	{
		this->first = pair.first;
		this->second = pair.second;
	}

};