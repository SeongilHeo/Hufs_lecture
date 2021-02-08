/*
 * template.h
 *
 *  Created on: 2017. 5. 17.
 *      Author: tjddl
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

template<class ItemType>
class Temp1
{
public:
	void setValue(ItemType input);
	ItemType getValue();
private:
	ItemType value;
};

template<class ItemType>
void Temp1<ItemType>::setValue(ItemType input)
{
    value = input;
}
template<class ItemType>
ItemType Temp1<ItemType>::getValue() {
    return value;
}

#endif /* TEMPLATE_H_ */
