#pragma once

// we dont put this in Serializer cause it shouldn't own or
// define the thing it is serializing.
struct Data
{
	int value;
};
