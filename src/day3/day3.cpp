#include <day3/day3.hpp>

Day3::Day3(){
    sumPriority = 0;
}

void Day3::splitRucksack(string rucksack, string* splittedRucksackFirstPart, string* splittedRucksackSecondPart){
    int rucksackLength = 0;

    rucksackLength = rucksack.size();
    *splittedRucksackFirstPart = rucksack.substr(0, rucksackLength/2);
    *splittedRucksackSecondPart = rucksack.substr(rucksackLength/2, rucksackLength);

}

void Day3::findItemOccurrences(string* splittedRucksackFirstPart, string* splittedRucksackSecondPart){
    int occurrences = 0;
    int itemPriority = 0;
    for(auto firstPartItem:*splittedRucksackFirstPart){
        occurrences = count(splittedRucksackSecondPart->begin(), splittedRucksackSecondPart->end(), firstPartItem);

        if(occurrences > 0){
            // Breaking on first item occurrence
            itemPriority = getItemPriority(firstPartItem);
            addSumPriority(itemPriority);
            break;
        }
    }
}

int Day3::getItemPriority(char item){
    int magicNumberConvertor;
    int itemPriority = 0;
    if(item > 90){
        // Lowercase
        magicNumberConvertor = 96;
    }

    else{
        // Uppercase
        magicNumberConvertor = 38;
    }
    itemPriority = item - magicNumberConvertor;

    return itemPriority;
}

void Day3::addSumPriority(int itemPriority){
    sumPriority += itemPriority;
}

int Day3::getSumPriority(){
    return sumPriority;
}
