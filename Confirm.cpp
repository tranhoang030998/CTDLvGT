#include "Confirm.h"

bool checkMode(eModeImportData mode, int key)
{
	if (mode == UPPER_LOWER)
	{
		if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z')
			return true;
		return false;
	}
	else if (mode == NUMBER)
	{
		if (key >= '0' && key <= '9')
			return true;
		return false;
	}
	else if (mode == UPPER)
	{
		if (key >= 'A' && key <= 'Z')
			return true;
		return false;
	}
	else if (mode == LOWER)
	{
		if (key >= 'a' && key <= 'z')
			return true;
		return false;
	}
	else if (mode == ALL)
	{
		if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z' || key >= '0' && key <= '9' || key == 32)
			return true;
		return false;
	}
	else if (mode == ALL_SPACE)
	{
		if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z' || key >= '0' && key <= '9' || key == 32)
			return true;
		return false;
	}
	else if (mode == UPPER_NUMBER)
	{
		if (key >= 'A' && key <= 'Z' || key >= '0' && key <= '9')
			return true;
		return false;
	}
	else if (mode == SEX)
	{
		if (key == '0' || key == '1')
			return true;
		return false;
	}
	else if (mode == TYPEBILL)
	{
		if (key == 'n' || key == 'N' || key == 'x' || key == 'X')
			return true;
		return false;
	}
	return false;
}

char* char_toUpper(char *text)
{
	int size = strlen(text);
	for (int run = 0; run < size; run++)
	{
		if (text[run] >= 'a' && text[run] <= 'z')
		{
			text[run] -= 32;
		}
	}
	return text;
}

char* char_toLower(char *text)
{
	int size = strlen(text);
	for (int run = 0; run < size; run++)
	{
		if (text[run] >= 'A' && text[run] <= 'Z')
		{
			text[run] += 32;
		}
	}
	return text;
}

void char_erase(char *&list, int LOCATIONDelete)
{
	if (LOCATIONDelete < 0 /*|| LOCATIONDelete > MaxEmployees*//* || List_IsEmpty(list)*/)
	{
		return;
	}
	int length = strlen(list);
	for (int i = LOCATIONDelete + 1; i < length; i++)
	{
		list[i - 1] = list[i];
	}
	list[length - 1] = '\0';
}

char* char_formartText(char *text)
{	
	int run = strlen(text) - 1;
	if (run >= 0)
	{
		// delete right
		while (text[run] == ' ')
		{
			run--;
			if (run < 0)
				return "";
		}

		if (run < static_cast<int>(strlen(text)) - 1)
		{
			text[run + 1] = '\0';
		}

		//delete left
		while (text[0] == ' ' || text[0] == '\0')
		{
			if (text[0] == '\0')
				return "";
			char_erase(text, 0);
		}

		int size = strlen(text) - 1;
		run = 0;
		//delete between
		if (size > 2)
		{
			for(int i = 0; i < size; i++)
			{
				if (text[i] == ' ' && text[i + 1] == ' ')
				{
					char_erase(text, i);
					i--;
					size = strlen(text) - 1;
				}
			}
		}

		//upper lower
		size = strlen(text);
		for (int i = 0; i < size; i++)
		{
			if (i == 0 && (text[0] >= 'a' && text[0] <= 'z'))
			{
				text[0] -= 32;
			}
			else if (text[i - 1] == ' ' && (text[i] >= 'a' && text[i] <= 'z'))
			{
				text[i] -= 32;
			}
			else
			{
				if (text[i] >= 'A' && text[i] <= 'Z')
				{
					text[i] += 32;
				}
			}
		}
		return text;
	}
	else
		return "";
}

char* char_substr(char *Source, unsigned int lcCut, unsigned int quantity)
{
	char *temp = new char[quantity + 1];
	temp[quantity] = '\0';
	if (lcCut >= strlen(Source) || lcCut + quantity  > strlen(Source))
	{
		return temp;
	}
	else
	{
		int size = strlen(Source);
		for (int i = 0; i < size; i++)
		{
			if (i == lcCut)
			{
				for (unsigned int j = 0; j < quantity; j++)
				{
					temp[j] = Source[i + j];
				}
				return temp;
			}
		}
	}
	return temp;
}

void char_insert(char *list, int LOCATIONAdd, char data)
{
	if (LOCATIONAdd < 0 || LOCATIONAdd > static_cast<int>(strlen(list)) /*|| isFull(list)*/)
	{
		return;
	}

	int length = strlen(list);
	for (int i = length - 1; i >= LOCATIONAdd; i--)
	{
		list[i + 1] = list[i];
	}
	list[LOCATIONAdd] = data;
	list[length + 1] = '\0';
}

char* EntryData(char *text, POINT lc, eModeImportData mode, int maxLength) // TEXT NUMBER UPPER LOWER ALL
{
	gotoxy(lc.x, lc.y); std::cout << text;
	int head = lc.x;

	bool isControl = false;
	while (true)
	{
		if (_kbhit())
		{// cho datansap xep lon xon,roi dung gi de load ra 1 file, co che no ntn
			char key = _getch();
			if (key == 13)
				return "\0";
			if ((key >= '0' && key <= '9' || key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z') && !isControl)
			{
				//cout << "not is  control" << endl;
				int lengthText = strlen(text);
				if (checkMode(mode, key) && lengthText <= maxLength) // condition
				{
					if (wherex() == head + lengthText && lengthText < maxLength)
					{
						char_insert(text, strlen(text), key);
						std::cout << key;
					}
					else
					{
						if (wherex() < (head + lengthText))
							text[wherex() - head] = (char)key;

						int x = wherex();
						gotoxy(head, wherey()); std::cout << text;
						gotoxy(x, wherey());
					}
				}
			}
			else if (key == -32)
			{
				isControl = true;
			}
			else if (isControl)
			{
				if (key == 80)
				{
					//cout << "DOWN";
				}
				else if (key == 72)
				{
					//cout << "UP";
				}
				else if (key == 75)
				{
					//cout << "LEFT";
					if (wherex() > head)
					{
						gotoxy(wherex() - 1, wherey());
					}
				}
				else if (key == 77)
				{
					//cout << "RIGHT";
					int lengthText = strlen(text);
					if (wherex() < head + lengthText)
					{
						gotoxy(wherex() + 1, wherey());
					}
				}
				isControl = false;
			}
			else
			{
				if (key == 8) // backSpace
				{
					int lengthText = strlen(text);
					if (wherex() == head + lengthText && strcmp(text, "") != 0)
					{
						char_erase(text, lengthText - 1);
						gotoxy(head, wherey()); std::cout << text << " ";
						gotoxy(wherex() - 1, wherey());
					}
					else
					{
						if (strcmp(text, "") != 0 && wherex() >= head)
						{
							if (wherex() == head)
							{
								char_erase(text, 0);
								gotoxy(head, wherey()); std::cout << text << " ";
								gotoxy(head, wherey());
							}
							else
							{
								int x = wherex();
								char_erase(text, wherex() - head);
								gotoxy(head, wherey()); std::cout << text << " ";
								gotoxy(x - 1, wherey());
							}
						}
					}
				}
				if (key == 13 && strcmp(text, "") != 0)
				{
					break;
				}
			}
		}
	}
	return text;
}
