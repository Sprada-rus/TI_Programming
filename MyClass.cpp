#include <stdio.h>
#include "MyClass.h"

void MyClassFindWords::setTextForAnalyze(System::String^ text) {
	System::String^ deliStr = " ,.!:\t\n";
	words = text->Split(deliStr->ToCharArray());
}

System::String^ MyClassFindWords::getMaxLenWords(int N) {
	System::String^ resultText = "";

	int countFindWord = 0;
	int maxCount = 0;

	for (int i = 0; i < words->Length; i++) {
		if (maxCount < words[i]->Length)
			maxCount = words[i]->Length;
	}

	for (int i = maxCount; i > 0; i--)
	{
		for (int j = 0; j < words->Length; j++) {
			if (countFindWord == N)
			{
				break;
			} else{
				if (words[j]->Length == maxCount) {
					resultText += " " + words[j];
					countFindWord++;
				}
			}
		}
		maxCount--;
	}
	
	return resultText;
}
