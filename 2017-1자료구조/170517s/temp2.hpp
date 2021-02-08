/*
 * temp2.hpp
 *
 *  Created on: 2017. 5. 17.
 *      Author: tjddl
 */

#ifndef TEMP2_HPP_
#define TEMP2_HPP_

template<class ItemType>
class Temp2
{
public:
	void setValue(ItemType input);
	ItemType getValue();
private:
	ItemType value;
};


#endif /* TEMP2_HPP_ */

/*print
if(ptr != NULL)
{
	cout<< ptr->data <<endl;
	return print(ptr->next);
}
