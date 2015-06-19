#!/bin/bash

sed -i 's/ICollectible.h/interfaces\/ICollectible.h/g' *.h
sed -i 's/ICollectible.h/interfaces\/ICollectible.h/g' *.cpp

sed -i 's/ICollection.h/interfaces\/ICollection.h/g' *.h
sed -i 's/ICollection.h/interfaces\/ICollection.h/g' *.cpp

sed -i 's/List.h/collections\/List.h/g' *.h
sed -i 's/List.h/collections\/List.h/g' *.cpp

sed -i 's/IDictionary.h/interfaces\/IDictionary.h/g' *.h
sed -i 's/IDictionary.h/interfaces\/IDictionary.h/g' *.cpp

sed -i 's/IIterator.h/interfaces\/IIterator.h/g' *.h
sed -i 's/IIterator.h/interfaces\/IIterator.h/g' *.cpp
