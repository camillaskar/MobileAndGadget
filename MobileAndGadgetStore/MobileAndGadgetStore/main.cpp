#include <iostream>
#include <string>

using namespace std;

struct productInfo {
	int product_id, product_quantity;
	string product_name;
	string category;
	double product_price;
	productInfo* next;

	productInfo() {
		product_id = 0;
		product_price = 0;
		product_quantity = 0;
		next = NULL;
	}
};

struct transactionInfo {
	int transaction_id, tmp_purchase_id;
	string transaction_name, transaction_quantity;
	double transaction_total_price;
	transactionInfo* next;

	transactionInfo() {
		tmp_purchase_id = 0;
		transaction_id = 0;
		transaction_total_price = 0;
		next = NULL;
	}
};

bool productIsEmpty(productInfo** product) {
	if ((*product) == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool transactionIsEmpty(transactionInfo** transaction) {
	if ((*transaction) == NULL) {
		return true;
	}
	else {
		return false;
	}
}

struct productInfo* producthead = NULL;
struct transactionInfo* transactionhead = NULL;

//Inventory
void newProduct() {
	struct productInfo* newProduct= new productInfo;
	struct productInfo* last = producthead;
	struct productInfo* newCategory = newProduct; 
	

	cout << "\nEnter a new product ID: " << endl;
	cin >> newProduct->product_id;
	while (!cin) {
		cout << "Please enter an integer. Enter a new product ID: ";
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
		cin >> newProduct->product_id;
	}

	while (newProduct->product_id < 0) {
		cout << "Please enter a positive number. Enter a new product ID: ";
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
		cin >> newProduct->product_id;
	}

	struct productInfo* checkID; //transverse the linked list to find similar ID
	checkID = producthead; //pointing at the beginning of the linked lists
	while (checkID != NULL) { //move through the node until the end of linked list

		if (newProduct->product_id == checkID->product_id) { //while looking at all node value, check if value cin = any of stud_id
			cout << "The product ID already exist! Please enter a new product ID: "; //if duplicate ask user to re-enter input for stud_id
			cin >> newProduct->product_id;
			checkID = producthead;
		}
		else {
			checkID = checkID->next; //if value cin != any of stud_id keep at looking the next node
		}
	}

	cout << "What is the name of the new product?" << endl;
	cin >> newProduct->product_name;

	cout << "What is the price of the new product?" << endl;
	while (!(cin >> newProduct->product_price)) {
		cout << "Please enter an integer/double value!" << endl;;
		cout << "What is the price of the new product?" << endl;
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
	}

	cout << "What is the stock quantity of the new product?" << endl;
	while (!(cin >> newProduct->product_quantity)) {
		cout << "Please enter an integer!" << endl;
		cout << "What is the stock quantity of the new product?" << endl;
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
	}

	cout<<"Enter category - Mobile || Headphones || PC :"<<endl;
	cin >> newCategory -> category; 
	
	newProduct->next = NULL;

	if (producthead == NULL) {
		producthead = newProduct;
		return;
	}
	else {
		while (last->next != NULL) {
			last = last->next;
		}

		last->next = newProduct;
		return;
	}
}

void viewProduct() {
	struct productInfo* display_product;


	if (producthead==NULL){
		cout<< "Empty list"<< endl;
	}
	else{
		display_product = producthead;
	cout << "\n-------------------Product List-------------------" << endl;
	cout << "Product ID \tProduct Name \tQuantity \tPrice \tCategory" << endl;
	while (display_product != NULL) {
		
		cout << display_product->product_id <<
			"\t\t" << display_product->product_name <<
			"\t\t" << display_product->product_quantity <<
			"\t\tRM" << display_product->product_price<< 
			"\t\t"<< display_product ->category << endl;
		display_product = display_product->next;
	}

}
}

void searchProduct(){
struct productInfo* IDsearch ;
    struct productInfo* temp = producthead;
    struct productInfo* current = producthead;
	string product_name;

	int searchID;

	cout << "\nEnter Product ID" << endl;
	cin >> searchID;

    while (current != NULL && current->product_id != searchID)
    {
        temp = current;
        current = current->next;
    }
    if (current != NULL)
    {
        IDsearch = current;
        current = current->next;
        std::cout << " - " << searchID<< " The product has found\n\n";
		cout << "Name: "<< temp ->product_name << "\n\n"<<
		cout << "Price: RM" << temp ->product_price <<endl;
    }
    else
    {
        std::cout << "There is no product with such ID\n\n";
    }
}

void sortProduct(){
	struct productInfo* current, *key = NULL;
	current = producthead;
	string temp_name;
	double temp_price;
	int temp_id;

	if (current == NULL){
		cout << "No item in the list";
	}
	else{
		while (current!=NULL){
			key = current -> next;

			while (key!=NULL){
				if (current->product_price> key ->product_price){
					temp_id = current ->product_id;
					temp_name = current ->product_name;
					temp_price = current -> product_price;
					current -> product_id = key ->product_id;
					current -> product_name = key -> product_name;
					current -> product_price = key -> product_price;
					key ->product_id = temp_id;
					key ->product_name= temp_name;
					key ->product_price = temp_price;
				}
				key = key ->next;
			}
			current = current ->next;
		}
	}
		viewProduct();
		cout << "The list has been sorted based on a price\n\n";
}




void updateData() {
    int searchID;
    cout << "Please enter ID: ";
    cin>>searchID;
    int ch;
    struct productInfo *current = producthead;
    struct productInfo *temp;

    if (producthead == NULL)
        cout << "No record to update!" << endl;
    else
    {
        current = producthead;

        while((current!=NULL) && (current->product_id!=searchID))
        {
            current=current->next; 
        }

        if (current==NULL)
            {cout<<"The Requested ID is Not Found" << endl;}


        else if(current->product_id==searchID)
        {
            cout<<"What Information You Want To Update?" << endl;
            cout<<"1. Price" << endl;
            cout<<"2. Quantity" << endl;
            cin>>ch;

            switch(ch)
            {
                case 1 :
                {
                    cout << "Enter New Price: ";
                    cin.ignore();
                    cin >> current->product_price;
                    break;
                }

                case 2 :
                {
                    cout<<"Enter New Quantityt: ";
                    cin >> current->product_quantity;
                    break;
                }

                default:
                {
                    cout<<"Wrong Input! Please choose again: ";
                    cin>>ch;
                }
            }
            cout<<"RECORD UPDATED !";
        }
    }
}




void deleteProduct() {
	struct productInfo* current = producthead;

	if (current == NULL) {
		cout << "No record in the list!\n\n";
	}
	else {
		bool found = true;

		viewProduct();
		cout << "\nEnter Product ID to delete: ";
		int deleteID;
		cin >> deleteID;

		while (current != NULL) {

			if (producthead->product_id == deleteID) {
				char choice;

				do {
					cout << "Are you sure you want to delete the product? (Y/N)" << endl;
					cin >> choice;
				} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

				if (choice == 'Y' || choice == 'y') {
					productInfo* firstNode = producthead;
					firstNode = firstNode->next;
					delete producthead;
					producthead = firstNode;
					found = true;
					cout << "\nProduct " << deleteID << " is deleted.\n\n" << endl;
					break;
				}
				else if (choice == 'N' || choice == 'n') {
					cout << "Delete function is cancelled.\n";
					return;
				}
			}
			else if (current->next == NULL) {

				cout << "Product with the entered ID does not exist!\n\n";
				cin.clear(); // reset failbit / clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
				return;
			}
			else if (current->next->product_id == deleteID) {
				//cout << "\nProduct ID \tProduct Name \tPrice \tQuantity" << endl;
				//cout << "" << current->next->product_id <<
				//	"\t \t" << current->next->product_price <<
				//	"\t \t" << current->next->product_price <<
				//	"\t" << current->next->product_quantity << endl;
				char choice;

				do {
					cout << "Are you sure you want to delete the product? (Y/N)" << endl;
					cin >> choice;
				} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

				if (choice == 'Y' || choice == 'y') {
					productInfo* prev = current;
					productInfo* todelete = current->next;
					prev->next = todelete->next;
					delete todelete;

					found = true;
					cout << "\nProduct " << deleteID << " is deleted.\n" << endl;
					break;
				}
				else if (choice == 'N' || choice == 'n') {
					cout << "Delete function is cancelled.\n" << endl;
					return;
				}
			}
			else {
				found = false;
				current = current->next;
			}
		}

		if (found == false) {
			cout << "Product with the entered ID does not exist!" << endl;
		}
	}
}



void productFilter(){
	struct productInfo*display = producthead; 
	string category;
	double product_price;
	int product_id;
	string category_in;
	int ch;

            cout<<"Choose the category:" << endl;
            cout<<"1. Mobile" << endl;
            cout<<"2. Headphones" << endl;
			cout<<"3. PC" << endl;
            cin>>ch;

            switch(ch)
            {
                case 1 :
                { 
                      cout << "\n-------------------Product List-------------------" << endl;
   					 cout << "Product ID \tProduct Name \tQuantity \tPrice" << endl;
  					  while (display!=NULL) {
         	           if (display->category == "Mobile"){
							cout <<  display->product_id<<
							 "\t\t" << display->product_name <<
           					 "\t\t" << display->product_quantity <<
           					 "\t\tRM" << display->product_price<< endl;
								display = display ->next;
						}
						else {
							cout<< "No items available" <<endl;
						}
						}
                
				break;
			}

                case 2 :
                {
                      cout << "\n-------------------Product List-------------------" << endl;
   					 cout << "Product ID \tProduct Name \tQuantity \tPrice" << endl;
  					 
         	           if (display->category == "Headphones"){
							cout <<  display->product_id<<
							 "\t\t" << display->product_name <<
           					 "\t\t" << display->product_quantity <<
           					 "\t\tRM" << display->product_price<< endl;
								display = display ->next;
						}
						else{
							cout<< "No items available" <<endl;
						}
                
				break;
				}

				case 3 :
				{ 
                      cout << "\n-------------------Product List-------------------" << endl;
   					 cout << "Product ID \tProduct Name \tQuantity \tPrice" << endl;
  					  
         	           if (display->category == "PC"){
							cout <<  display->product_id<<
							 "\t\t" << display->product_name <<
           					 "\t\t" << display->product_quantity <<
           					 "\t\tRM" << display->product_price<< endl;
								display = display ->next;
						}
						else{
							cout<< "No items available" <<endl;
						}
				
				break;
				}

                default:
                {
                    cout<<"Wrong Input! Please choose again: ";
                    cin>>ch;
                }
            }
}
        



	



//Transaction 
void newTransaction() {
	struct transactionInfo* newTransaction = new transactionInfo;
	struct transactionInfo* last = transactionhead;
	int purchase_quantity;
	double pricePaid, totalPrice = 0;
	char choice;

	struct productInfo* oriProductList;
	oriProductList = producthead;

	if (oriProductList == NULL) {
		cout << "No product is in the list to purchase!\n\n";
		return;
	}
	else {
		cout << "\nEnter a new transaction ID: ";
		cin >> newTransaction->transaction_id;
		while (!cin) {
			cout << "Please enter an integer. Enter a new transaction ID: ";
			cin.clear(); // reset failbit / clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
			cin >> newTransaction->transaction_id;
		}

		while (newTransaction->transaction_id < 0) {
			cout << "Please enter a positive number. Enter a new transaction ID: ";
			cin.clear(); // reset failbit / clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
			cin >> newTransaction->transaction_id;
		}

		struct transactionInfo* checkID;
		checkID = transactionhead;
		while (checkID != NULL) {

			if (newTransaction->transaction_id == checkID->transaction_id) {
				cout << "The transaction ID already exist! Please enter a new transaction ID: ";
				cin >> newTransaction->transaction_id;
				checkID = transactionhead;
			}
			else {
				checkID = checkID->next;
			}

		}

		do {
			bool found = false;
			viewProduct();
			cout << "\nPlease insert the ID of the product you wish to purchase: ";
			cin >> newTransaction->tmp_purchase_id;
			while (!cin) {
				cout << "Please enter an integer. Please insert the ID of the product you wish to purchase: ";
				cin.clear(); // reset failbit / clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
				cin >> newTransaction->tmp_purchase_id;
			}

			/*while (oriProductList->next != NULL)
			{
				if (oriProductList->product_id == newTransaction->tmp_purchase_id) {
					found = true;
					break;
				}
				oriProductList = oriProductList->next;
			}*/


			//transaction_name = "1,2";
			//transaction_quantity = "1,2"
			//	for (i = 0; i < transactionname.split.count; i++) {
			//		if (oriProductList->product_id == transactionname.split[i])
			//		{
			//			oriProductList->quantity + int.parse(transactionquantity.split[i])
			//		}

			//	}
			//	quantity + 


			/*
			if (newTransaction->tmp_purchase_id) {
				found = false;
			}*/

			while (oriProductList != NULL) {

				if (newTransaction->tmp_purchase_id == oriProductList->product_id && oriProductList->product_quantity <= 0) {
					cout << "There is no available stock! Please purchase another item!\n\n";

					struct productInfo* oriprod = oriProductList;
					string delimiter = ",";

					size_t pos = 0;
					string q, n;

					while ((pos = newTransaction->transaction_name.find(delimiter)) != string::npos) {
						n = newTransaction->transaction_name.substr(0, pos);
						newTransaction->transaction_name.erase(0, pos + delimiter.length());

						while ((pos = newTransaction->transaction_quantity.find(delimiter)) != string::npos) {
							q = newTransaction->transaction_quantity.substr(0, pos);
							newTransaction->transaction_quantity.erase(0, pos + delimiter.length());

							while (!oriProductList->product_name.empty()) {
								if (oriProductList->product_name == n) {
									//cout << "value of n: " << n << endl;
									oriProductList->product_quantity = oriProductList->product_quantity + stoi(q);
									//cout << "value of q: " << q << endl;
									//oriprod = oriProductList;
									break;
								}
								oriProductList = oriProductList->next;
							}
							oriProductList = producthead;
							break;
						}
					}

					while (!oriProductList->product_name.empty()) {
						//cout << "product name: " << oriProductList->product_name << endl;
						//cout << "transaction product name: " << newTransaction->transaction_name << endl;
						if (oriProductList->product_name == newTransaction->transaction_name) {
							//cout << "value of product q: " << oriProductList->product_quantity << endl;
							//cout << "value of purchase q: " << newTransaction->transaction_quantity << endl;
							oriProductList->product_quantity = oriProductList->product_quantity + stoi(newTransaction->transaction_quantity);
							break;
						}
						else {
							oriProductList = oriProductList->next;
						}

					}

					return;
				}
				else if (newTransaction->tmp_purchase_id == oriProductList->product_id) {
					found = true;
					cout << "Please enter quantity to purchase: ";
					cin >> purchase_quantity;
					cin.clear(); // reset failbit / clear error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag


					while (purchase_quantity > oriProductList->product_quantity || purchase_quantity < 1 && purchase_quantity < oriProductList->product_quantity) {
						cout << "Please enter a valid amount: ";
						cin >> purchase_quantity;
						cin.clear(); // reset failbit / clear error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
					}

					totalPrice = totalPrice + oriProductList->product_price * purchase_quantity;
					if (newTransaction->transaction_name.empty()) {
						newTransaction->transaction_name = oriProductList->product_name;
					}
					else {
						newTransaction->transaction_name = newTransaction->transaction_name + "," + oriProductList->product_name;
					}

					if (newTransaction->transaction_quantity.empty()) {
						newTransaction->transaction_quantity = to_string(purchase_quantity);
					}
					else {
						newTransaction->transaction_quantity = newTransaction->transaction_quantity + "," + to_string(purchase_quantity);
					}

					newTransaction->transaction_total_price = totalPrice;
					oriProductList->product_quantity = oriProductList->product_quantity - purchase_quantity;

					do {
						cout << "Do you want to buy another product? (Y/N)" << endl;
						cin >> choice;
					} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

					break;
				}
				else {
					oriProductList = oriProductList->next;
				}
			}

			oriProductList = producthead;
			if (found == false) {
				cout << "Product with the entered ID does not exist!\n\n";
				break;
			}
		} while (choice == 'Y' || choice == 'y' && choice != 'N' && choice != 'n');

		if (choice == 'N' || choice == 'n') {

			cout << "\nThe total price is RM" << totalPrice << endl;
			cout << "How much do you want to pay? ";
			cin >> pricePaid;
			while (!cin) {
				cout << "Please enter an integer. How much do you want to pay: ";
				cin.clear(); // reset failbit / clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
				cin >> pricePaid;
			}

			if (pricePaid < totalPrice) {
				cout << "\nInsufficient funds to purchase the items!\n\n";

				struct productInfo* oriprod = oriProductList;
				string delimiter = ",";

				size_t pos = 0;
				string q,n;

				while ((pos = newTransaction->transaction_name.find(delimiter)) != string::npos) {
					n = newTransaction->transaction_name.substr(0, pos);
					newTransaction->transaction_name.erase(0, pos + delimiter.length());

					while ((pos = newTransaction->transaction_quantity.find(delimiter)) != string::npos) {
						q = newTransaction->transaction_quantity.substr(0, pos);
						newTransaction->transaction_quantity.erase(0, pos + delimiter.length());

						while (!oriProductList->product_name.empty()) {
							if (oriProductList->product_name == n) {
								//cout << "value of n: " << n << endl;
								oriProductList->product_quantity = oriProductList->product_quantity + stoi(q);
								//cout << "value of q: " << q << endl;
								//oriprod = oriProductList;
								break;
							}
							oriProductList = oriProductList->next;
						}
						oriProductList = producthead;
						break;
					}
				}

				while (!oriProductList->product_name.empty()) {
					//cout << "product name: " << oriProductList->product_name << endl;
					//cout << "transaction product name: " << newTransaction->transaction_name << endl;
					if (oriProductList->product_name == newTransaction->transaction_name) {
						//cout << "value of product q: " << oriProductList->product_quantity << endl;
						//cout << "value of purchase q: " << newTransaction->transaction_quantity << endl;
						oriProductList->product_quantity = oriProductList->product_quantity + stoi(newTransaction->transaction_quantity);
						break;
					}
					else {
						oriProductList = oriProductList->next;
					}

				}

				//while (oriProductList->next != NULL) {
				//	if (oriProductList->product_name == newTransaction->transaction_name) {
				//		oriProductList->product_quantity = oriProductList->product_quantity + stoi(newTransaction->transaction_quantity);
				//		break;
				//	}
				//	//oriprod = oriprod->next;
				//	oriProductList = oriProductList->next;
				//}

				//if (oriProductList->product_name == newTransaction->transaction_name) {
				//	oriProductList->product_quantity = oriProductList->product_quantity + stoi(newTransaction->transaction_quantity);
				//}

				newTransaction->transaction_quantity = newTransaction->transaction_quantity.empty();
				newTransaction->transaction_name = newTransaction->transaction_name.empty();
				totalPrice = 0;
				cin.clear(); // reset failbit / clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag
				return;
			}
			else {
				cout << "\nYou have successfully purchased the items! Your change is RM" << pricePaid - totalPrice << "\n\n";


				newTransaction->next = NULL;

				if (transactionhead == NULL) {
					transactionhead = newTransaction;
					return;
				}
				else {
					while (last->next != NULL) {
						last = last->next;
					}

					last->next = newTransaction;
					return;
				}
			}
		}
	}
}

void viewTransaction() {

	struct transactionInfo* display_transaction;

	display_transaction = transactionhead;

	if (display_transaction == NULL) {
		cout << "No transaction records!" << endl;
	}
	else {
		cout << "Transaction ID \tProduct Purchased \tQuantity \tTotal Price" << endl;
		while (display_transaction != NULL) {
			cout << display_transaction->transaction_id <<
				"\t\t" << display_transaction->transaction_name <<
				"\t\t\t" << display_transaction->transaction_quantity <<
				"\t\tRM" << display_transaction->transaction_total_price << endl;
			display_transaction = display_transaction->next;
		}
	}
}

void sortTransaction() {
    struct transactionInfo* current, *index = NULL; 
    current = transactionhead;
    string temp_name, temp_quantity;
    double temp_price;
    int temp_id;

    if (current == NULL) {
        cout << "No transaction records to sort!\n\n";
    }
    else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                //If current node's product_price is greater than index's node product_price, swap the product_price between them  
                if (current->transaction_total_price > index->transaction_total_price) {
                    temp_id = current->transaction_id;
                    temp_name = current->transaction_name;
                    temp_price = current->transaction_total_price;
                    temp_quantity = current->transaction_quantity;
                    current->transaction_id = index->transaction_id;
                    current->transaction_name = index->transaction_name;
                    current->transaction_total_price = index->transaction_total_price;
                    current->transaction_quantity = index->transaction_quantity;
                    index->transaction_id = temp_id;
                    index->transaction_name = temp_name;
                    index->transaction_total_price = temp_price;
                    index->transaction_quantity = temp_quantity;
                }
                index = index->next;
            }
            current = current->next;
        }
        cout << "The list is sorted based on total price!\n\n";
    }
}


void purchaseDetail() {
	//traverse
	transactionInfo* current = transactionhead;

	if (current == NULL) {
		cout << "No record in the list\n";
	}
	else {
		int value;
		cout << "Enter transaction ID for purchase detail: ";
		cin >> value;

		bool found = false;

		while (current != NULL) {
			//viewTransaction();

			if (current->transaction_id == value) {
				cout << "\nTransaction ID \tProduct Name \tQuantity \tTotal Price" << endl;
				cout << current->transaction_id <<
					"\t\t" << current->transaction_name <<
					"\t\t" << current->transaction_quantity <<
					"\t\t" << current->transaction_total_price << "\n\n";
				current = current->next;
				found = true;
				break;
			}
			else {
				found = false;
				current = current->next;
			}
		}

		if (found == false) {
			cout << "Transaction not found!\n\n";
		}
	}
}

//Menu
void mainMenu() {
	cout << "--------------- Mobile and Gadget Store ---------------" << endl;
	cout << "1 for Inventory Menu\n" << endl;
	cout << "2 for Transaction Menu\n" << endl;
	cout << "3 to exit\n" << endl;
	cout << "Enter your choice: ";
}

void inventoryMenu() {
	int subchoice;

	do {
		cout << "\n--------------- Inventory Menu ---------------" << endl;
		cout << "1 for Add New Product\n" << endl;
		cout << "2 for Display All Product\n" << endl;
		cout << "3 for Product Search\n" << endl;
		cout << "4 for Category Filter\n" << endl;
		cout << "5 for Update Product\n" << endl;
		cout << "6 for Sort Product\n" << endl;
		cout << "7 for Delete Product\n" << endl;
		cout << "8 to Back to Main Menu\n" << endl;
		cout << "Enter your choice: ";
		cin >> subchoice;
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag

		switch (subchoice) {
		case 1:
			newProduct();
			break;
		case 2:
			viewProduct();
			cout << endl;
			break;
		case 3:
			searchProduct();
			cout << endl;
			break;
		case 4:
			productFilter();
			cout << endl;
			break;
		case 5:
			updateData();
			cout << endl;
			break;
		case 6:
			sortProduct();
			cout  << endl;
			break;
		case 7:
			deleteProduct();
			break;
		case 8:
			cout << "\nBack to main menu was chosen!\n" << endl;
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (subchoice != 8);
}

void transactionMenu() {
	int subchoice;

	do {
		cout << "\n--------------- Transaction Menu ---------------" << endl;
		cout << "1 for Add New Purchase\n" << endl;
		cout << "2 for View Purchase\n" << endl;
		cout << "3 for Sort Purchase\n" << endl;
		cout << "4 for Purchase Detail\n" << endl;
		cout << "5 to Back to Main Menu\n" << endl;
		cout << "Enter your choice: ";
		cin >> subchoice;
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag

		switch (subchoice) {
		case 1:
			newTransaction();
			break;
		case 2:
			viewTransaction();
			cout << endl;
			break;
		case 3:
			
			break;
		case 4:
			purchaseDetail();
			break;
		case 5:
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (subchoice != 5);
}

int main() {

	int choice;
	do {
		mainMenu();
		cin >> choice;
		cin.clear(); // reset failbit / clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input / clear error flag

		switch (choice) {
		case 1:
			inventoryMenu();
			break;
		case 2:
			transactionMenu();
			break;
		case 3:
			cout << "\nThank you for using my Mobile and Gadget Store! Bye Bye!" << endl;
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 3);

}

