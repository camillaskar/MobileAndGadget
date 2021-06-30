//#include <iostream>
//#include "Inventory.h"
//
//using namespace std;
//
//Inventory::Inventory() {
//	struct productInfo* producthead = NULL;
//}
//
//void Inventory::newProduct() {
//	struct productInfo* newProduct = new productInfo;
//	struct productInfo* last = producthead;
//	newProduct->next = NULL;
//
//	cout << "Enter a new product ID: " << endl;
//	while (!(cin >> newProduct->product_id)) {
//		cout << "Please enter an integer!" << endl;;
//		cout << "Enter a new product ID: " << endl;
//		cin.clear();
//		cin.ignore(123, '\n');
//	}
//
//	struct productInfo* checkID; //transverse the linked list to find similar ID
//	checkID = producthead; //pointing at the beginning of the linked lists
//	while (checkID != NULL) { //move through the node until the end of linked list
//
//		if (newProduct->product_id == checkID->product_id) { //while looking at all node value, check if value cin = any of stud_id
//			cout << "The product ID already exist! Please enter a new product ID: "; //if duplicate ask user to re-enter input for stud_id
//			cin >> newProduct->product_id;
//		}
//		else {
//			checkID = checkID->next; //if value cin != any of stud_id keep at looking the next node
//		}
//	}
//
//	cout << "What is the name of the new product?" << endl;
//	cin >> newProduct->product_name;
//
//	cout << "What is the price of the new product?" << endl;
//	while (!(cin >> newProduct->product_price)) {
//		cout << "Please enter an integer/double value!" << endl;;
//		cout << "What is the price of the new product?" << endl;
//		cin.clear();
//		cin.ignore(123, '\n');
//	}
//
//	cout << "What is the stock quantity of the new product?" << endl;
//	while (!(cin >> newProduct->product_quantity)) {
//		cout << "Please enter an integer!" << endl;
//		cout << "What is the stock quantity of the new product?" << endl;
//		cin.clear();
//		cin.ignore(123, '\n');
//	}
//
//	if (producthead == NULL) {
//		producthead = newProduct;
//		return;
//	}
//	else {
//		while (last->next != NULL) {
//			last = last->next;
//		}
//
//		last->next = newProduct;
//		return;
//	}
//}
//
//void Inventory::viewProduct() {
//	struct productInfo* display_product;
//
//	display_product = producthead;
//
//	cout << "Product ID \tProduct Name \tPrice \tQuantity" << endl;
//	while (display_product != NULL) {
//		cout << display_product->product_id <<
//			"\t\t" << display_product->product_name <<
//			"\t\t" << display_product->product_price <<
//			"\t" << display_product->product_quantity << endl;
//		display_product = display_product->next;
//	}
//
//}
//
//void Inventory::deleteProduct() {
//	struct productInfo* current = producthead;
//
//	if (current == NULL) {
//		cout << "No record in the list!\n\n";
//	}
//	else {
//		bool found = true;
//
//		viewProduct();
//		cout << "\nEnter Product ID to delete: ";
//		int deleteID;
//		cin >> deleteID;
//
//		while (current != NULL) {
//
//			if (producthead->product_id == deleteID) {
//				char choice;
//
//				do {
//					cout << "Are you sure you want to delete the product? (Y/N)" << endl;
//					cin >> choice;
//				} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
//
//				if (choice == 'Y' || choice == 'y') {
//					productInfo* firstNode = producthead;
//					firstNode = firstNode->next;
//					delete producthead;
//					producthead = firstNode;
//					found = true;
//					cout << "\nProduct " << deleteID << " is deleted.\n\n" << endl;
//					break;
//				}
//				else if (choice == 'N' || choice == 'n') {
//					cout << "Delete function is cancelled.\n";
//					return;
//				}
//			}
//			else if (current->next == NULL) {
//
//				cout << "Product with the entered ID does not exist!\n\n";
//				cin.clear();
//				cin.ignore(123, '\n');
//				return;
//			}
//			else if (current->next->product_id == deleteID) {
//				//cout << "\nProduct ID \tProduct Name \tPrice \tQuantity" << endl;
//				//cout << "" << current->next->product_id <<
//				//	"\t \t" << current->next->product_price <<
//				//	"\t \t" << current->next->product_price <<
//				//	"\t" << current->next->product_quantity << endl;
//				char choice;
//
//				do {
//					cout << "Are you sure you want to delete the product? (Y/N)" << endl;
//					cin >> choice;
//				} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
//
//				if (choice == 'Y' || choice == 'y') {
//					productInfo* prev = current;
//					productInfo* todelete = current->next;
//					prev->next = todelete->next;
//					delete todelete;
//
//					found = true;
//					cout << "\nStudent " << deleteID << " is deleted.\n" << endl;
//					break;
//				}
//				else if (choice == 'N' || choice == 'n') {
//					cout << "Delete function is cancelled.\n" << endl;
//					return;
//				}
//			}
//			else {
//				found = false;
//				current = current->next;
//			}
//		}
//
//		if (found == false) {
//			cout << "Product with the entered ID does not exist!" << endl;
//		}
//	}
//}