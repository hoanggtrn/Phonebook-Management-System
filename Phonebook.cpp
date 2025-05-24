/*
De Tai: Quan Ly Danh Ba So Dien Thoai
Mon: Lap trinh huong doi tuong voi C++
Lop: OOPC336964_23_2_03CLC - HCMUTE
GVHD: Tran Thi Quynh Nhu
Nhom 2:
    1. Do Le Viet Hoang - 20119314
    2. Le Cong Bac - 20119199
    3. Tran Nguyen Khanh Hoang - 20119315
    4. Nguyen Viet Binh - 20119202
*/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <limits>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

class Contact
{
public:
    int ordinalNumber;
    std::string name, phone;
    char favorite;

    Contact(int ordinalNumber = 0, std::string name = "", std::string phone = "", char favorite = '.')
    {
        this->ordinalNumber = ordinalNumber;
        this->name = name;
        this->phone = phone;
        this->favorite = favorite;
    }

    void show_Contact() // Displaying a contact
    {
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||                             THONG TIN LIEN HE                           ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||=========================================================================||\n";
        std::cout << "|| STT ||           Ho ten          ||      So dien thoai     || Yeu thich ||\n";
        std::cout << "||-------------------------------------------------------------------------||\n";
        std::cout << "||" << std::setw(3) << this->ordinalNumber << std::setw(26) << this->name << std::setw(24) << this->phone << std::setw(14) << this->favorite << std::setw(8) << "||"
                  << "\n";
    }

    std::string lower_Case(std::string word) // Converting the string to lowercase
    {
        for (int i = 0; i < word.size(); i++)
            (word[i] >= 65 && word[i] <= 90 ? word[i] += 32 : word[i] += 0);
        return word;
    }

    bool find(std::string word) // Searching for a contact by name
    {
        word = lower_Case(word);
        return lower_Case(name).find(word) != std::string::npos;
    }

    bool find_phone(std::string word) { return lower_Case(phone).find(word) != std::string::npos; } // Searching for a contact by phone
};

class PhoneBook
{
    std::vector<Contact> contacts;

public:
    bool end = false;

    PhoneBook() { input_Contacts(); }
    ~PhoneBook() { update_Contacts(); }

    void input_Contacts() // Reading the data from the file
    {
        std::ifstream input_Contacts("Contacts_list.txt");
        int ordinalNumber;
        std::string name, phone;
        char favorite;
        while (input_Contacts >> ordinalNumber >> name >> phone >> favorite)
        {
            for (int i = 0; i < name.size(); i++)
                if (name[i] == '*')
                    name[i] = ' ';

            contacts.emplace_back(ordinalNumber, name, phone, favorite);
        }
    }

    void update_Contacts() // Writing the data to the file
    {
        std::ofstream output_Contacts("Contacts_list.txt");
        for (int i = 0; i < contacts.size(); i++)
        {
            for (int j = 0; j < contacts[i].name.size(); j++)
                if (contacts[i].name[j] == ' ')
                    contacts[i].name[j] = '*';

            output_Contacts << "  " << contacts[i].ordinalNumber << std::setw(21) << contacts[i].name << std::setw(22) << contacts[i].phone << std::setw(23) << contacts[i].favorite << std::setw(6) << "\n";
        }
    }

    void swap_Contacts() // Sorting the contacts by name
    {
        for (int i = 0; i < contacts.size(); i++)
            for (int j = 0; j < contacts.size(); j++)
                if (lower(contacts[i].name) < lower(contacts[j].name) && i != j)
                    std::swap(contacts[i], contacts[j]);
    }

    std::string lower(std::string name) // Converting the string to lowercase
    {
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] >= 'A' && name[i] <= 'Z')
                name[i] += 32;
        }
        return name;
    }

    void processing_Name(std::string &name) // Processing the name
    {
        while (name[0] == ' ')
            name.erase(0, 1);
        while (name[name.length() - 1] == ' ')
            name.erase(name.length() - 1);
        int indexName = 0;
        while (indexName < name.length())
        {
            if (name[indexName] == ' ' && name[indexName + 1] == ' ')
                name.erase(indexName, 1);
            else
                indexName++;
        }
        for (int indexName = 0; indexName < name.length(); indexName++)
            name[indexName] = tolower(name[indexName]);
        name[0] = toupper(name[0]);
        for (int indexName = 0; indexName < name.length(); indexName++)
        {
            if (name[indexName] == ' ' && name[indexName + 1] != ' ')
                name[indexName + 1] = toupper(name[indexName + 1]);
        }
    }

    void processing_Phone(std::string &phone) // Processing the phone
    {
        while (phone[0] == ' ')
            phone.erase(0, 1);
        while (phone[phone.length() - 1] == ' ')
            phone.erase(phone.length() - 1);
        int indexPhone = 0;
        while (indexPhone < phone.length())
        {
            if (phone[indexPhone] == ' ')
                phone.erase(indexPhone, 1);
            else
                indexPhone++;
        }
    }

    void new_Contact() // Adding a new contact
    {
        int ordinalNumber, i = 0;
        bool add = false, same = false;
        bool isValidChoice = false;
        std::string name, phone;
        char favorite = '.';

        while (true)
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                           2 - THEM LIEN HE MOI                          ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Nhap ten lien he moi: ";

            if (std::cin.peek() == '\n')
                std::cin.ignore();
            std::getline(std::cin, name);

            if (!name.empty())
                break;

            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||          *** Ten khong duoc de trong! ... Vui long nhap lai ***         ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
        }

    New_Phone:
        std::cout << "  >> Nhap so dien thoai lien moi: ";
        std::getline(std::cin, phone);

        processing_Phone(phone); // Processing the phone
        for (char digit : phone) // Check if the phone number contains only digits
        {
            if (!isdigit(digit))
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||  *** So dien thoai chi duoc chua cac chu so! ... Vui long nhap lai ***  ||\n";
                std::cout << ">>=========================================================================<<\n";
                goto New_Phone;
            }
        }
        if (phone.length() != 10) // Check if the phone number has 10 digits
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||      *** So dien thoai phai co 10 chu so! ... Vui long nhap lai ***     ||\n";
            std::cout << ">>=========================================================================<<\n";
            goto New_Phone;
        }

        ordinalNumber = contacts.size() + 1; // Assigning the ordinal number to the new contact

        processing_Name(name); // Processing the name

        for (int j = 0; j < contacts.size(); j++) // Checking if the phone number is already in the list
        {
            if (lower(contacts[j].phone) == lower(phone))
            {
                same = true;
                break;
            }
        }

        if (same)
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||       *** Khong hop le! ... Da co so lien he trung voi so nay ***       ||\n";
        Try_Add:
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Nhap lai                                                         ||\n";
            std::cout << "||    2 - Tro ve menu chinh                                                ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "  >> Chon chuc nang thuc hien: ";

            char choiceAdd;
            std::cin >> choiceAdd;
            if (choiceAdd == '1')
                new_Contact();
            else if (choiceAdd == '2')
                Interface();
            else
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "\n";
                goto Try_Add;
            }
        }

    Favorite_Choice:
        char favoriteChoice;
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||     BAN CO MUON THEM LIEN HE VAO YEU THICH KHONG? (Yes[y] or No[n]):    ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Lua chon cua ban: ";
        while (!isValidChoice)
        {
            std::cin >> favoriteChoice;
            if (favoriteChoice == 'y' || favoriteChoice == 'Y')
            {
                favorite = '#';
                isValidChoice = true;
            }
            else if (favoriteChoice == 'n' || favoriteChoice == 'N')
                isValidChoice = true;

            else
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                goto Favorite_Choice;
            }
        }

        Contact C1(ordinalNumber, name, phone, favorite); // Creating a new contact

        // Adding the new contact to the list
        for (auto it = contacts.begin(); it != contacts.end(); it++, i++)
        {
            if (it->name > name || i == contacts.size())
            {
                auto it = contacts.insert(contacts.begin() + i, C1);
                add = true;
                break;
            }
        }

        if (!add)
            contacts.push_back(C1);

        for (int j = 0; j < contacts.size(); j++)
            contacts[j].ordinalNumber = j + 1;

        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||                  !!!! MOT LIEN HE MOI DA DUOC THEM !!!!                 ||\n";
        std::cout << "||                                                                         ||\n";
    Again_Add:
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||          BAN CO MUON THEM MOT LIEN HE KHAC? (Yes[y] or No[n]):          ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Lua chon cua ban: ";

        char yesNoAdd;
        std::cin >> yesNoAdd;
        if (yesNoAdd == 'y' || yesNoAdd == 'Y')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            new_Contact();
        }
        else if (yesNoAdd == 'n' || yesNoAdd == 'N')
            Interface();
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto Again_Add;
        }
    }

    void search_Contact() // Searching for a contact
    {
        char choiceSearch;
    Again_Search:
        system("cls");
        if (!contacts.empty())
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                           3 - TIM KIEM LIEN HE                          ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Tim kiem lien he theo ten                                        ||\n";
            std::cout << "||    2 - Tim kiem lien he theo so dien thoai                              ||\n";
            std::cout << "||    3 - Tro ve menu chinh                                                ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << ">> Chon chuc nang thuc hien: ";

            std::cin >> choiceSearch;
            switch (choiceSearch)
            {
            case '1':
                search_By_Name();
                break;
            case '2':
                search_By_Phone();
                break;
            case '3':
                Interface();
                break;
            default:
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "\n";
                system("pause");
                goto Again_Search;
            }
        }
        else
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                           3 - TIM KIEM LIEN HE                          ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                     !!!! KHONG TIM THAY LIEN HE !!!!                    ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            Interface();
        }
    }

    void search_By_Name() // Searching for a contact by name
    {
        bool isFound = false, duplicated = false;
        std::string name;

        // system("cls");
        // std::cout << ">>=========================================================================<<\n";
        // std::cout << "||                       3 - TIM KIEM LIEN HE THEO TEN                     ||\n";
        // std::cout << "||=========================================================================||\n";
        // std::cout << "  >> Nhap ten cua lien he can tim: ";
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // std::getline(std::cin, name);

        while (true)
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                       3 - TIM KIEM LIEN HE THEO TEN                     ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Nhap ten cua lien he can tim: ";

            if (std::cin.peek() == '\n')
                std::cin.ignore();
            std::getline(std::cin, name);

            if (!name.empty())
                break;

            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||          *** Ten khong duoc de trong! ... Vui long nhap lai ***         ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
        }
        processing_Name(name); // Processing the name

        for (int it = 0; it < contacts.size(); it++)
        {
            if (lower(contacts[it].name) == lower(name) || contacts[it].find(name))
            {
                isFound = true;
                if (!duplicated)
                {
                    contacts[it].show_Contact();
                    duplicated = true;
                }
                else
                    std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber
                              << std::setw(26) << contacts[it].name
                              << std::setw(24) << contacts[it].phone
                              << std::setw(14) << contacts[it].favorite
                              << std::setw(8) << "||"
                              << "\n";
            }
        }

        if (!isFound)
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong tim thay lien he voi ten nay! ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
        Try_Search_By_Name:
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Nhap lai                                                         ||\n";
            std::cout << "||    2 - Tro ve menu tim kiem                                             ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "  >> Chon chuc nang thuc hien: ";

            char choiceSearchByName;
            std::cin >> choiceSearchByName;
            if (choiceSearchByName == '1')
                search_By_Name();
            else if (choiceSearchByName == '2')
                search_Contact();
            else
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                goto Try_Search_By_Name;
            }
        }
    Again_Search_By_Name:
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||           BAN CO MUON TIM THEM LIEN HE KHAC? (Yes[y] or No[n]):         ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Lua chon cua ban: ";

        char yesNoSearchByName;
        std::cin >> yesNoSearchByName;
        if (yesNoSearchByName == 'y' or yesNoSearchByName == 'Y')
            search_By_Name();
        else if (yesNoSearchByName == 'n' or yesNoSearchByName == 'N')
            search_Contact();
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            goto Again_Search_By_Name;
        }
    }

    void search_By_Phone() // Searching for a contact by phone
    {
        bool isFound = false, duplicated = false;
        std::string phone;

    Phone_Check:
        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                  3 - TIM KIEM LIEN HE THEO SO DIEN THOAI                ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Nhap so dien thoai cua lien he can tim: ";

        if (std::cin.peek() == '\n')
            std::cin.ignore();
        std::getline(std::cin, phone);
        processing_Phone(phone); // Processing the phone

        for (char digit : phone) // Check if the phone number contains only digits
        {
            if (!isdigit(digit))
            {
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||  *** So dien thoai chi duoc chua cac chu so! ... Vui long nhap lai ***  ||\n";
                std::cout << ">>=========================================================================<<\n";
                system("pause");
                goto Phone_Check;
            }
        }
        if (phone.empty())
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||     *** So dien thoai khong duoc de trong! ... Vui long nhap lai ***    ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            goto Phone_Check;
        }

        for (int it = 0; it < contacts.size(); it++)
        {
            if (contacts[it].phone == phone || contacts[it].find_phone(phone))
            {
                isFound = true;
                if (!duplicated)
                {
                    contacts[it].show_Contact();
                    duplicated = true;
                }
                else
                    std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber << std::setw(26) << contacts[it].name << std::setw(24) << contacts[it].phone << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                              << "\n";
            }
        }
        if (!isFound)
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||           *** Khong tim thay lien he voi so dien thoai nay! ***         ||\n";
            std::cout << ">>=========================================================================<<\n";
        Try_Search_By_Phone:
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Nhap lai                                                         ||\n";
            std::cout << "||    2 - Tro ve menu tim kiem                                             ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "  >> Chon chuc nang thuc hien: ";
            char choiceSearchByPhone;
            std::cin >> choiceSearchByPhone;
            if (choiceSearchByPhone == '1')
                search_By_Phone();
            else if (choiceSearchByPhone == '2')
                search_Contact();
            else
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                goto Try_Search_By_Phone;
            }
        }
    Again_Search_By_Phone:
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||           BAN CO MUON TIM THEM LIEN HE KHAC? (Yes[y] or No[n]):         ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Lua chon cua ban: ";
        char yesNoSearchByPhone;
        std::cin >> yesNoSearchByPhone;
        if (yesNoSearchByPhone == 'y' or yesNoSearchByPhone == 'Y')
            search_By_Phone();
        else if (yesNoSearchByPhone == 'n' or yesNoSearchByPhone == 'N')
            search_Contact();
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            goto Again_Search_By_Phone;
        }
    }

    void delete_Contact() // Deleting a contact or all contacts
    {
        char choiceDelete;
    Again_Del:
        system("cls");
        if (!contacts.empty())
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                              4 - XOA LIEN HE                            ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Xoa lien he                                                      ||\n";
            std::cout << "||    2 - Xoa tat ca lien he                                               ||\n";
            std::cout << "||    3 - Tro ve menu chinh                                                ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "\n";
            std::cout << "  >> Chon chuc nang thuc hien: ";

            std::cin >> choiceDelete;
            switch (choiceDelete)
            {
            case '1':
                delete_SingleContact();
                break;
            case '2':
                delete_All_Contacts();
                break;
            case '3':
                system("cls"), Interface();
                break;
            default:
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "\n";
                system("pause");
                goto Again_Del;
            }
        }
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                              4 - XOA LIEN HE                            ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                     !!!! KHONG TIM THAY LIEN HE !!!!                    ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            Interface();
        }
    }

    void delete_SingleContact() // Deleting a single contact
    {
        std::string name, phone;
        bool isFound = false, duplicated = false;
        int ordinalNumber, counter = 0;

        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                              4 - XOA LIEN HE                            ||\n";
        std::cout << "||=========================================================================||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||    1 - Chon so thu tu de xoa lien he                                    ||\n";
        std::cout << "||    2 - Tim ten de xoa lien he                                           ||\n";
        std::cout << "||    3 - Tim so dien thoai de xoa lien he                                 ||\n";
        std::cout << "||    4 - Tro ve menu xoa lien he                                          ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "\n";
        std::cout << "  >> Chon chuc nang thuc hien: ";
        char pressDelete;
        std::cin >> pressDelete;
        system("cls");
        if (pressDelete == '1')
        {
            system("cls");
            show_All_Contact();
        Contact_Delete:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                              4 - XOA LIEN HE                            ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Nhap so thu tu cua lien he can xoa: ";
            std::cin >> ordinalNumber;
        }
        else if (pressDelete == '2')
        {
            system("cls");
        Search_Name_Delete:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                              4 - XOA LIEN HE                            ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Tim ten cua lien he can xoa: ";

            if (std::cin.peek() == '\n')
                std::cin.ignore();
            std::getline(std::cin, name);
            if (name.empty())
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||          *** Ten khong duoc de trong! ... Vui long nhap lai ***         ||\n";
                std::cout << ">>=========================================================================<<\n";
                goto Search_Name_Delete;
            }
            processing_Name(name);

            system("cls");
            for (int it = 0; it < contacts.size(); it++) // Searching for the contact by name
            {
                if (lower(contacts[it].name) == lower(name) || contacts[it].find(name))
                {
                    isFound = true;
                    if (!duplicated)
                    {
                        contacts[it].show_Contact();
                        duplicated = true;
                    }
                    else
                        std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber << std::setw(26) << contacts[it].name << std::setw(24) << contacts[it].phone << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                                  << "\n";
                }
            }
            std::cout << ">>=========================================================================<<\n";

            if (!isFound)
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong tim thay lien he voi ten nay! ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
            Try_Search_By_Name:
                std::cout << "||                                                                         ||\n";
                std::cout << "||    1 - Nhap lai                                                         ||\n";
                std::cout << "||    2 - Tro ve menu xoa lien he                                          ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "  >> Chon chuc nang thuc hien: ";

                char choiceSearchByName;
                std::cin >> choiceSearchByName;
                if (choiceSearchByName == '1')
                    goto Search_Name_Delete;
                else if (choiceSearchByName == '2')
                    delete_SingleContact();
                else
                {
                    system("cls");
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    goto Try_Search_By_Name;
                }
            }
            goto Contact_Delete;
        }
        else if (pressDelete == '3')
        {
            system("cls");
        Search_Phone_Delete:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                              4 - XOA LIEN HE                            ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Tim so dien thoai cua lien he can xoa: ";

            if (std::cin.peek() == '\n')
                std::cin.ignore();
            std::getline(std::cin, phone);
            processing_Phone(phone); // Processing the phone

            for (char digit : phone) // Check if the phone number contains only digits
            {
                if (!isdigit(digit))
                {
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||  *** So dien thoai chi duoc chua cac chu so! ... Vui long nhap lai ***  ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    system("pause");
                    goto Search_Phone_Delete;
                }
            }
            if (phone.empty())
            {
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||     *** So dien thoai khong duoc de trong! ... Vui long nhap lai ***    ||\n";
                std::cout << ">>=========================================================================<<\n";
                system("pause");
                goto Search_Phone_Delete;
            }

            system("cls");
            for (int it = 0; it < contacts.size(); it++) // Searching for the contact by phone
            {
                if (contacts[it].phone == phone || contacts[it].find_phone(phone))
                {
                    isFound = true;
                    if (!duplicated)
                    {
                        contacts[it].show_Contact();
                        duplicated = true;
                    }
                    else
                        std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber << std::setw(26) << contacts[it].name << std::setw(24) << contacts[it].phone << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                                  << "\n";
                }
            }
            std::cout << ">>=========================================================================<<\n";

            if (!isFound)
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||           *** Khong tim thay lien he voi so dien thoai nay! ***         ||\n";
                std::cout << ">>=========================================================================<<\n";
            Try_Search_By_Phone:
                std::cout << "||                                                                         ||\n";
                std::cout << "||    1 - Nhap lai                                                         ||\n";
                std::cout << "||    2 - Tro ve menu xoa lien he                                          ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "  >> Chon chuc nang thuc hien: ";
                char choiceSearchByPhone;
                std::cin >> choiceSearchByPhone;
                switch (choiceSearchByPhone)
                {
                case '1':
                    goto Search_Phone_Delete;
                    break;
                case '2':
                    delete_SingleContact();
                    break;
                default:
                    system("cls");
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    goto Try_Search_By_Phone;
                    break;
                }
            }
            goto Contact_Delete;
        }
        else if (pressDelete == '4')
            delete_Contact();
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            delete_SingleContact();
        }

        system("cls");
        for (auto it = contacts.begin(); it != contacts.end(); it++, counter++)
        {
            if (lower(it->name) == lower(name) || it->phone == phone || counter + 1 == ordinalNumber)
            {
                isFound = true;
                it->show_Contact();
            Choice_Delete_Contact:
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                      *** Lien he nay se duoc xoa! ***                    ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||                DONG Y XOA LIEN HE NAY? (Yes[y] or No[n]):               ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "  >> Lua chon cua ban: ";
                char choiceDeleteContact;
                std::cin >> choiceDeleteContact;
                if (choiceDeleteContact == 'y' or choiceDeleteContact == 'Y')
                {
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << "||                       !!!! LIEN HE DA DUOC XOA !!!!                     ||\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << ">>=========================================================================<<\n";

                    contacts.erase(it);
                    for (int i = 0; i < contacts.size(); i++)
                        contacts[i].ordinalNumber = i + 1;

                Again_Delete_Contact:
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << "||           BAN CO MUON XOA THEM LIEN HE KHAC? (Yes[y] or No[n]):         ||\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "  >> Lua chon cua ban: ";
                    char yesNoDelete;
                    std::cin >> yesNoDelete;
                    if (yesNoDelete == 'y' or yesNoDelete == 'Y')
                        delete_SingleContact();
                    else if (yesNoDelete == 'n' or yesNoDelete == 'N')
                        delete_Contact();
                    else
                    {
                        system("cls");
                        std::cout << ">>=========================================================================<<\n";
                        std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                        std::cout << ">>=========================================================================<<\n";
                        goto Again_Delete_Contact;
                    }
                    break;
                }
                else if (choiceDeleteContact == 'n' or choiceDeleteContact == 'N')
                    delete_SingleContact();
                else
                {
                    system("cls");
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    system("pause");
                    goto Choice_Delete_Contact;
                }
            }
        }

        for (int i = 0; i < contacts.size(); i++) // Updating the ordinal numbers
            contacts[i].ordinalNumber = i + 1;

        if (!isFound)
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||      *** Khong tim thay lien he phu hop! ... Vui long nhap lai ***      ||\n";
        Try_Delete_Contact:
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||    1 - Nhap lai                                                         ||\n";
            std::cout << "||    2 - Tro ve menu xoa lien he                                          ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "  >> Chon chuc nang thuc hien: ";
            char choiceDel;
            std::cin >> choiceDel;
            if (choiceDel == '1')
                delete_SingleContact();
            else if (choiceDel == '2')
                delete_Contact();
            else
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                goto Try_Delete_Contact;
            }
        }
    }

    void delete_All_Contacts() // Deleting all contacts
    {
        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||         BAN CO CHAC MUON XOA TAT CA LIEN HE? (Yes[y] or No[n]):         ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Lua chon cua ban: ";
        char choiceDeleteAll;
        std::cin >> choiceDeleteAll;
        if (choiceDeleteAll == 'y' or choiceDeleteAll == 'Y')
        {
        Confirm_Delete_All:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||       VIEC XOA TAT CA KHONG THE KHOI PHUC LAI? (Yes[y] or No[n]):       ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Lua chon cua ban: ";
            char choiceDeleteAllconfirm;
            std::cin >> choiceDeleteAllconfirm;
            if (choiceDeleteAllconfirm == 'y' or choiceDeleteAllconfirm == 'Y')
            {
                contacts.clear();
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||                   !!!! TAT CA LIEN HE DA DUOC XOA !!!!                  ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << ">>=========================================================================<<\n";
            }
            else if (choiceDeleteAllconfirm == 'n' or choiceDeleteAllconfirm == 'N')
                delete_Contact();
            else
            {
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
                system("pause");
                goto Confirm_Delete_All;
            }
        }
        else if (choiceDeleteAll != 'n' or choiceDeleteAll != 'N')
            delete_Contact();
        else
        {
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            delete_All_Contacts();
        }
    }

    void modify_Contact() // Modifying a contact
    {
        bool isFound = false, same = false, duplicated = false;
        std::string name, modifiedName, modifiedPhone, choiceModify, phone;
        int ordinalNumber;
        char favorite, modifiedFav;

        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                           5 - CHINH SUA LIEN HE                         ||\n";
        std::cout << "||=========================================================================||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||    1 - Nhap so thu tu lien he can chinh sua                             ||\n";
        std::cout << "||    2 - Tim ten lien he can chinh sua                                    ||\n";
        std::cout << "||    3 - Tim so dien thoai lien he can chinh sua                          ||\n";
        std::cout << "||    4 - Tro ve menu chinh                                                ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "  >> Chon chuc nang thuc hien: ";

        int pressModify;
        std::cin >> pressModify;

        switch (pressModify)
        {
        case 1:
            system("cls");
            show_All_Contact();
        Edit_By_Ordinal_Number:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                       5 - CHINH SUA LIEN HE THEO STT                    ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Nhap so thu tu cua lien he can chinh sua: ";
            std::cin >> ordinalNumber;
            break;
        case 2:
            system("cls");
        Search_Name_Edit:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                       5 - CHINH SUA LIEN HE THEO TEN                    ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "  >> Tim ten cua lien he can chinh sua: ";
            std::getline(std::cin, name), std::getline(std::cin, name);
            processing_Name(name);
            system("cls");
            for (int it = 0; it < contacts.size(); it++)
            {
                if (lower(contacts[it].name) == lower(name) || contacts[it].find(name))
                {
                    isFound = true;
                    if (!duplicated)
                    {
                        contacts[it].show_Contact();
                        duplicated = true;
                    }
                    else
                        std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber << std::setw(26) << contacts[it].name << std::setw(24) << contacts[it].phone << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                                  << "\n";
                }
            }
            std::cout << ">>=========================================================================<<\n";

            if (!isFound)
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                *** Khong tim thay lien he voi ten nay! ***              ||\n";
                std::cout << ">>=========================================================================<<\n";
            Try_Search_By_Name:
                std::cout << "||                                                                         ||\n";
                std::cout << "||    1 - Nhap lai                                                         ||\n";
                std::cout << "||    2 - Tro ve menu chinh                                                ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "  >> Chon chuc nang thuc hien: ";

                int choiceSearchByName;
                std::cin >> choiceSearchByName;
                if (choiceSearchByName == 1)
                    goto Search_Name_Edit;
                else if (choiceSearchByName == 2)
                    Interface();
                else
                {
                    system("cls");
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    goto Try_Search_By_Name;
                }
            }
            goto Edit_By_Ordinal_Number;
            break;
        case 3:
            system("cls");
        Search_Phone_Edit:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                  5 - CHINH SUA LIEN HE THEO SO DIEN THOAI               ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << " >> Tim so dien thoai cua lien he can chinh sua: ";
            std::getline(std::cin, phone), std::getline(std::cin, phone);
            processing_Phone(phone);
            system("cls");
            for (int it = 0; it < contacts.size(); it++)
            {
                if (contacts[it].phone == phone || contacts[it].find_phone(phone))
                {
                    isFound = true;
                    if (!duplicated)
                    {
                        contacts[it].show_Contact();
                        duplicated = true;
                    }
                    else
                        std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber << std::setw(26) << contacts[it].name << std::setw(24) << contacts[it].phone << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                                  << "\n";
                }
            }
            std::cout << ">>=========================================================================<<\n";

            if (!isFound)
            {
                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||           *** Khong tim thay lien he voi so dien thoai nay! ***         ||\n";
                std::cout << ">>=========================================================================<<\n";
            Try_Search_By_Phone:
                std::cout << "||                                                                         ||\n";
                std::cout << "||    1 - Nhap lai                                                         ||\n";
                std::cout << "||    2 - Tro ve menu chinh                                                ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "  >> Chon chuc nang thuc hien: ";
                int choiceSearchByPhone;
                std::cin >> choiceSearchByPhone;
                switch (choiceSearchByPhone)
                {
                case 1:
                    goto Search_Phone_Edit;
                    break;
                case 2:
                    Interface();
                    break;
                default:
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    goto Try_Search_By_Phone;
                    break;
                }
            }
            goto Edit_By_Ordinal_Number;
            break;
        case 4:
            system("cls"), Interface();
            break;
        default:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            system("pause");
            modify_Contact();
            break;
        }
        system("cls");
        for (int it = 0; it < contacts.size(); it++)
        {
            if (lower(contacts[it].name) == lower(name) || contacts[it].phone == phone || it + 1 == ordinalNumber)
            {
                isFound = true;
            Modify_Options:
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                          5 - CHINH SUA LIEN HE                          ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||    1 - Chinh sua ten                                                    ||\n";
                std::cout << "||    2 - Chinh sua so dien thoai                                          ||\n";
                std::cout << "||    3 - Chinh sua nhan yeu thich cua lien he                             ||\n";
                std::cout << "||    4 - Tro ve menu chinh                                                ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "  >> Chon chuc nang thuc hien: ";
                int pressMod;
                std::cin >> pressMod;

                system("cls");
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                          5 - CHINH SUA LIEN HE                          ||\n";
                std::cout << "||=========================================================================||\n";
                switch (pressMod)
                {
                case 1:
                    std::cout << "  >> Nhap ten moi cua lien he: ";
                    std::getline(std::cin, modifiedName), getline(std::cin, modifiedName);
                    break;
                case 2:
                    std::cout << "  >> Nhap so dien thoai moi cua lien he: ";
                    // std::cin >> modifiedPhone;
                    std::getline(std::cin, modifiedPhone), getline(std::cin, modifiedPhone);
                    break;
                case 3:
                    if (contacts[it].favorite == '#')
                    {
                    Non_Fav_Change:
                        system("cls");
                        std::cout << "||=========================================================================||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||*** Ban co muon doi lien he nay sang lien he thuong? (Yes[y] or No[n])***||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||=========================================================================||\n";
                        std::cout << "  >> Lua chon cua ban: ";
                        char yesNoNonFavorite;
                        std::cin >> yesNoNonFavorite;
                        if (yesNoNonFavorite == 'y' or yesNoNonFavorite == 'Y')
                            modifiedFav = '.';
                        else if (yesNoNonFavorite == 'n' or yesNoNonFavorite == 'N')
                        	 modifiedFav = '#';
                        else
                        {
                            std::cout << "||=========================================================================||\n";
                            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                            std::cout << "||=========================================================================||\n";
                            _getch();
                            goto Non_Fav_Change;
                        }
                        break;
                    }
                    else if (contacts[it].favorite == '.')
                    {
                    Fav_Change:
                        system("cls");
                        std::cout << "||=========================================================================||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||        *** Ban co muon doi lien he nay sang lien he yeu thich? ***      ||\n";
                        std::cout << "||                             (Yes[y] or No[n])                           ||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||=========================================================================||\n";
                        std::cout << "  >> Lua chon cua ban: ";
                        char yesNoFavorite;
                        std::cin >> yesNoFavorite;
                        if (yesNoFavorite == 'y' or yesNoFavorite == 'Y')
                            modifiedFav = '#';
                        else if (yesNoFavorite == 'n' or yesNoFavorite == 'N')
                        	modifiedFav = '.';
                        else
                        {
                            std::cout << "||=========================================================================||\n";
                            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                            std::cout << "||=========================================================================||\n";
                            _getch();
                            goto Fav_Change;
                        }
                        break;
                    }
                    break;
                case 4:
                    system("cls"), Interface();
                    break;
                default:
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "\n";
                    system("pause");
                    system("cls");
                    goto Modify_Options;
                    break;
                }

                //----------------------Processing the name--------------------------
                // Remove leading whitespace
                while (modifiedName[0] == ' ')
                    modifiedName.erase(0, 1);
                // Remove trailing whitespace
                while (modifiedName[modifiedName.length() - 1] == ' ')
                    modifiedName.erase(modifiedName.length() - 1);
                // Remove spaces between words
                int str = 0;
                while (str < modifiedName.length())
                {
                    if (modifiedName[str] == ' ' && modifiedName[str + 1] == ' ')
                        modifiedName.erase(str, 1);
                    else
                        str++;
                }
                // Lowercase all characters
                for (int str = 0; str < modifiedName.length(); str++)
                    modifiedName[str] = tolower(modifiedName[str]);
                // Capitalize the first letter of each word
                modifiedName[0] = toupper(modifiedName[0]);
                for (int str = 0; str < modifiedName.length(); str++)
                {
                    if (modifiedName[str] == ' ' && modifiedName[str + 1] != ' ')
                        modifiedName[str + 1] = toupper(modifiedName[str + 1]);
                }
                //-------------------------End processing the name-------------------------

                Contact C1(it + 1, modifiedName, modifiedPhone, modifiedFav); // Modified a contact

                for (int j = 0; j < contacts.size(); j++) // Check if the modified contact is the same as the existing contact
                {
                    if (contacts[j].phone == modifiedPhone)
                    {
                        same = true;
                        break;
                    }
                }
                if (pressMod != 1)
                {
                    if (same)
                    {
                        system("cls");
                        std::cout << ">>=========================================================================<<\n";
                        std::cout << "||       *** Khong hop le! ... Da co so lien he trung voi so nay ***       ||\n";
                    Try_Modify_Contact:
                        std::cout << "||=========================================================================||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||    1 - Nhap lai                                                         ||\n";
                        std::cout << "||    2 - Tro ve menu chinh                                                ||\n";
                        std::cout << "||                                                                         ||\n";
                        std::cout << "||=========================================================================||\n";
                        std::cout << "  >> Chon chuc nang thuc hien: ";
                        int choiceModifyContact;
                        std::cin >> choiceModifyContact;
                        if (choiceModifyContact == 1)
                            modify_Contact();
                        else if (choiceModifyContact == 2)
                            Interface();
                        else
                        {
                            std::cout << ">>=========================================================================<<\n";
                            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                            std::cout << ">>=========================================================================<<\n";
                            goto Try_Modify_Contact;
                        }
                    }
                }
                contacts[it].show_Contact();
            Choice:
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                  *** Lien he nay se duoc chinh sua ***                  ||\n";
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||            !!!! CHINH SUA LIEN HE NAY? (Yes[y] or No[n]) !!!!           ||\n";
                std::cout << "||                                                                         ||\n";
                std::cout << "||=========================================================================||\n";
                std::cout << "  >> Lua chon cua ban: ";
                std::cin >> choiceModify;
                if (lower(choiceModify) == "y")
                {
                    for (int i = 0; i < contacts.size(); i++)
                    {
                        if ((pressMod == 2 /*|| pressMod == 3*/) && contacts[i].phone == contacts[it].phone)
                        {
                            Contact C2(contacts.size() + 1, contacts[it].name, contacts[it].phone, contacts[it].favorite);
                            contacts[i] = C2;
                        }
                        if (contacts[i].phone == contacts[it].phone && contacts[i].name != C1.name && pressMod == 1)
                        {
                            Contact C2(contacts.size() + 1, modifiedName, contacts[it].phone, contacts[it].favorite);
                            contacts[i] = C2;
                        }
                    }
                    if (pressMod == 1)
                        contacts[it].name = modifiedName;
                    else if (pressMod == 2)
                        contacts[it].phone = modifiedPhone;
                    // else if (pressMod == 3)
                    //     contacts[it] = C1;
                    else if (pressMod == 3)
                        contacts[it].favorite = modifiedFav;

                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                  !!!! CHINH SUA LIEN HE THANH CONG !!!!                 ||\n";
                    std::cout << ">>=========================================================================<<\n";

                    swap_Contacts();
                    for (int i = 0; i < contacts.size(); i++)
                        contacts[i].ordinalNumber = i + 1;

                Again_Modify_Contact:
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << "||       BAN CO MUON CHINH SUA THEM LIEN HE KHAC? (Yes[y] or No[n]):       ||\n";
                    std::cout << "||                                                                         ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "  >> Lua chon cua ban: ";
                    char yesNoModifyContact;
                    std::cin >> yesNoModifyContact;
                    if (yesNoModifyContact == 'y' or yesNoModifyContact == 'Y')
                        modify_Contact();
                    else if (yesNoModifyContact == 'n' or yesNoModifyContact == 'N')
                        Interface();
                    else
                    {
                        std::cout << ">>=========================================================================<<\n";
                        std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                        std::cout << ">>=========================================================================<<\n";
                        std::cout << "\n";
                        goto Again_Modify_Contact;
                    }
                }
                else if (lower(choiceModify) == "n")
                    Interface();
                else
                {
                    std::cout << ">>=========================================================================<<\n";
                    std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
                    std::cout << ">>=========================================================================<<\n";
                    system("pause");
                    goto Choice;
                }
                break;
            }
        }
        if (!isFound)
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||         *** Khong co lien he phu hop! ... Vui long nhap lai ***         ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "\n";
            system("pause");
            modify_Contact();
        }
    }

    void show_All_Contact() // Display all contacts
    {
        if (contacts.empty())
        {
            std::cout << "Khong tim thay lien he\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                        THONG TIN TAT CA LIEN HE                         ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                     !!!! KHONG TIM THAY LIEN HE !!!!                    ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << ">>=========================================================================<<\n";
        }
        else
        {
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                        THONG TIN TAT CA LIEN HE                         ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "|| STT ||           Ho ten          ||      So dien thoai     || Yeu thich ||\n";
            std::cout << "||-------------------------------------------------------------------------||\n";
            for (int it = 0; it < contacts.size(); it++)
            {
                std::cout << "||" << std::setw(3) << contacts[it].ordinalNumber
                          << std::setw(26) << contacts[it].name
                          << std::setw(24) << contacts[it].phone
                          << std::setw(14) << contacts[it].favorite << std::setw(8) << "||"
                          << "\n";
            }
            std::cout << ">>=========================================================================<<\n";
        }
    }

    void Interface() // Main menu
    {
        system("cls");
        std::cout << ">>=========================================================================<<\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||                              QUAN LY DANH BA                            ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||=========================================================================||\n";
        std::cout << "||                                MENU CHINH                               ||\n";
        std::cout << "||=========================================================================||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << "||    1 - Hien thi tat ca lien he                                          ||\n";
        std::cout << "||    2 - Them lien he moi                                                 ||\n";
        std::cout << "||    3 - Tim kiem lien he                                                 ||\n";
        std::cout << "||    4 - Xoa lien he                                                      ||\n";
        std::cout << "||    5 - Chinh sua lien he                                                ||\n";
        std::cout << "||    0 - Thoat va luu danh ba                                             ||\n";
        std::cout << "||                                                                         ||\n";
        std::cout << ">>=========================================================================<<\n";
        std::cout << "\n";
        std::cout << "  >> Chon chuc nang thuc hien: ";

        char mainKey;
        std::cin >> mainKey;
        system("cls");
        switch (mainKey)
        {
        case '1':
            show_All_Contact();
            break;
        case '2':
            new_Contact();
            break;
        case '3':
            search_Contact();
            break;
        case '4':
            delete_Contact();
            break;
        case '5':
            if (!contacts.empty())
                modify_Contact();
            else
            {
                std::cout << ">>=========================================================================<<\n";
                std::cout << "||                     !!!! KHONG TIM THAY LIEN HE !!!!                    ||\n";
                std::cout << ">>=========================================================================<<\n";
                break;
            }
        case '0':
            end = true;
            system("cls");
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                              QUAN LY DANH BA                            ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                  LIEN HE                                ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||                                  NHOM 2                                 ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||    Tran Nguyen Khanh Hoang  - 20119315                                  ||\n";
            std::cout << "||    Do Le Viet Hoang         - 20119314                                  ||\n";
            std::cout << "||    Le Cong Bac              - 20119199                                  ||\n";
            std::cout << "||    Nguyen Viet Binh         - 20119202                                  ||\n";
            std::cout << "||                                                                         ||\n";
            std::cout << "||=========================================================================||\n";
            std::cout << "||                     *** THANKS FOR USING THE APP ***                    ||\n";
            std::cout << ">>=========================================================================<<\n";
            update_Contacts();
            system("pause");
            exit(0);
            break;
        default:
            std::cout << ">>=========================================================================<<\n";
            std::cout << "||                *** Khong hop le! ... Vui long nhap lai ***              ||\n";
            std::cout << ">>=========================================================================<<\n";
            std::cout << "\n";
            break;
        }

        system("pause");
        Interface();
    }
    void display_Intro() // Display the introduction
    {
        std::vector<std::string> asciiArt = {
            ">>===========================================================<<",
            "||                                                           ||",
            "||   ____  _    _         _   _   _  __     __               ||",
            "||  / __ \\| |  | |  /\\   | \\ | | | | \\ \\   / /               ||",
            "|| | |  | | |  | | /  \\  |  \\| | | |  \\ \\_/ /                ||",
            "|| | |  | | |  | |/ /\\ \\ | . ` | | |   \\   /                 ||",
            "|| | |__| | |__| / ____ \\| |\\  | | |____| |                  ||",
            "||  \\___\\_\\____/_/    \\_|_| \\_| |______|_|                   ||",
            "||              _____          _   _ _    _   ____           ||",
            "||             |  __ \\   /\\   | \\ | | |  | | |  _ \\   /\\     ||",
            "||             | |  | | /  \\  |  \\| | |__| | | |_) | /  \\    ||",
            "||             | |  | |/ /\\ \\ | . ` |  __  | |  _ < / /\\ \\   ||",
            "||             | |__| / ____ \\| |\\  | |  | | | |_) / ____ \\  ||",
            "||             |_____/_/    \\_|_| \\_|_|  |_| |____/_/    \\_\\ ||",
            "||                                                           ||",
            ">>===========================================================<<"};

        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        int offset = (consoleWidth - asciiArt[0].size()) / 2;
        int padding = (consoleHeight - asciiArt.size()) / 3;

        for (int i = 0; i < padding; ++i)
        {
            std::cout << std::endl;
        }
        for (const auto &line : asciiArt)
        {
            std::cout << std::string(offset, ' ') << line << std::endl;
        }

        int startMessageOffset = (consoleWidth - 29) / 2;

        std::cout << std::endl
                  << std::string(startMessageOffset, ' ') << "...Press any key to start..." << std::endl;

        _getch();
    }
};

int main()
{
    PhoneBook PhoneBook;
    PhoneBook.display_Intro();
    while (!PhoneBook.end)
        PhoneBook.Interface();
}
