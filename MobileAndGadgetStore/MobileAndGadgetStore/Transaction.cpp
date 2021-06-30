//#include <iostream>
//#include "Transaction.h"
//#include "Inventory.h"
//
//using namespace std;
//
//Transaction::Transaction() {
//	struct transactionInfo* transactionhead = NULL;
//}
//
//void Transaction::newTransaction() {
//	struct transactionInfo* newTransaction = new transactionInfo;
//	struct transactionInfo* last = transactionhead;
//	newTransaction->next = NULL;
//	int purchase_quantity;
//	double price, totalPrice = 0;
//	char choice{};
//
//	cout << "Enter a new transaction ID: " << endl;
//	while (!(cin >> newTransaction->transaction_id)) {
//		cout << "Please enter an integer!" << endl;;
//		cout << "Enter a new transaction ID: " << endl;
//		cin.clear();
//		cin.ignore(123, '\n');
//	}
//
//	struct transactionInfo* checkID; //transverse the linked list to find similar ID
//	checkID = transactionhead; //pointing at the beginning of the linked lists
//	while (checkID != NULL) { //move through the node until the end of linked list
//
//		if (newTransaction->transaction_id == checkID->transaction_id) { //while looking at all node value, check if value cin = any of stud_id
//			cout << "The transaction ID already exist! Please enter a new product ID: "; //if duplicate ask user to re-enter input for stud_id
//			cin >> newTransaction->transaction_id;
//		}
//		else {
//			checkID = checkID->next; //if value cin != any of stud_id keep at looking the next node
//		}
//	}
//
//	if (checkID == NULL) {
//		cout << "No product is in the list!" << endl;
//	}
//	else {
//		cout << "\n";
//		viewProduct();
//		cout << "\nPlease insert the ID of the product you wish to purchase: ";
//		cin >> newTransaction->tmp_id_purchase;
//
//		struct productInfo* oriList; //transverse the linked list to find similar ID
//		oriList = producthead; //pointing at the beginning of the linked lists
//		while (oriList != NULL) { //move through the node until the end of linked list
//
//			if (newTransaction->tmp_id_purchase == oriList->product_id) { //while looking at all node value, check if value cin = any of stud_id
//
//				cout << "Please enter quantity to purchase: ";
//				cin >> purchase_quantity;
//
//				// if quantity = 0? how?
//
//				if (purchase_quantity > oriList->product_quantity) {
//					cout << "There is insufficient stock! Please enter a smaller amount. ";
//					cin.clear();
//					cin.ignore(123, '\n');
//				}
//				else if (purchase_quantity < 1) {
//					cout << "Please enter a positive amount! ";
//					cin.clear();
//					cin.ignore(123, '\n');
//				}
//				else {
//					totalPrice = totalPrice + oriList->product_price * purchase_quantity;
//					cout << "\nThe total price is RM" << totalPrice << endl;
//
//					cout << "How much do you want to pay? ";
//					cin >> price;
//					if (price < totalPrice) {
//						cout << "\nInsufficient funds to purchase the items! Please pay the correct amount. ";
//						cin.clear();
//						cin.ignore(123, '\n');
//					}
//					else {
//						cout << "\nYou have successfully purchased the items! Your change is RM" << price - totalPrice << "\n\n";
//						newTransaction->transaction_name = oriList->product_name;
//						newTransaction->transaction_quantity = purchase_quantity;
//						newTransaction->transaction_total_price = totalPrice;
//						oriList->product_quantity = oriList->product_quantity - purchase_quantity;
//
//
//
//						if (transactionhead == NULL) {
//							transactionhead = newTransaction;
//							return;
//						}
//						else {
//							while (last->next != NULL) {
//								last = last->next;
//							}
//
//							last->next = newTransaction;
//							return;
//						}
//					}
//				}
//			}
//			else {
//				oriList = oriList->next;
//			}
//		}
//	}
//}
//
//
//void Transaction::viewTransaction() {
//
//	struct transactionInfo* display_transaction;
//
//	display_transaction = transactionhead;
//
//	if (display_transaction == NULL) {
//		cout << "No transaction records!" << endl;
//	}
//	else {
//		cout << "Transaction ID \tProduct Name \tQuantity \tTotal Price" << endl;
//		while (display_transaction != NULL) {
//			cout << display_transaction->transaction_id <<
//				"\t\t" << display_transaction->transaction_name <<
//				"\t\t" << display_transaction->transaction_quantity <<
//				"\t\t" << display_transaction->transaction_total_price << endl;
//			display_transaction = display_transaction->next;
//		}
//	}
//}
//
//void Transaction::purchaseDetail() {
//	//traverse
//	transactionInfo* current = transactionhead;
//
//	if (current == NULL) {
//		cout << "No record in the list\n";
//	}
//	else {
//		int value;
//		cout << "Enter transaction ID for purchase detail: ";
//		cin >> value;
//
//		bool found = false;
//
//		while (current != NULL) {
//			//viewTransaction();
//
//			if (current->transaction_id == value) {
//				cout << "\nTransaction ID \tProduct Name \tQuantity \tTotal Price" << endl;
//				cout << current->transaction_id <<
//					"\t\t" << current->transaction_name <<
//					"\t\t" << current->transaction_quantity <<
//					"\t\t" << current->transaction_total_price << "\n\n";
//				current = current->next;
//				found = true;
//				break;
//			}
//			else {
//				found = false;
//				current = current->next;
//			}
//		}
//
//		if (found == false) {
//			cout << "Transaction not found!\n\n";
//		}
//	}
//}