#pragma once
#ifndef nodestruct_h
#define nodestruct_h

template <class T>
struct NodeStruct
{
	T data;
	NodeStruct <T>* next;
};
#endif