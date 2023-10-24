#include <iostream>
#include <fstream>
#include <cmath>
#include "BST.h"
#include "Queuet.cpp"

using namespace std;
const float PI = 3.14;

template <class keytype, class datatype>
BST <keytype, datatype> :: BST()
{
    root = NULL;
}

template <class keytype, class datatype>
bool BST <keytype, datatype> :: insert(treenode &Root, const keytype &k, const keytype &d1, const datatype &d2, const datatype &d3,const datatype &d4, const datatype &d5,const datatype &d6, const datatype &d7)
{

  if (Root == NULL)
  { 
    Root = new treenode; 
    Root->left = NULL; 
    Root->right = NULL;
    Root->key = k;
	Root->country_name = d1;
	Root->latitude = d2;
	Root->longitude = d3;
	Root->longitude2 = d4;
	Root->latitude2 = d5;
    return true;
  }
  else if (k == Root->key)
    return false;  
  else if (k < Root->key)
    return insert (Root->left, k, d1, d2, d3,d4,d5); 
  else
    return insert (Root->right, k, d1, d2, d3,d4,d5); 
}

template <class keytype, class datatype>
bool BST <keytype, datatype> :: empty() const
{
    return (root == NULL);
}
template <class keytype, class datatype>
bool BST <keytype, datatype> :: search (const keytype &k, treenode* Root) const
{
  if (Root == NULL)      
		return false;                     
    else if (k == Root->key)
		return true; 
    else if (k < Root->key)
		return search(Root->left, k); 
    else
		return search(Root->right, k); 
}
template <class keytype, class datatype>
bool BST <keytype, datatype> :: retrieve (treenode* Root, const keytype &k, keytype &d1, datatype &d2, datatype &d3, datatype &d4, datatype &d5,const datatype &d6, const datatype &d7) const
{
 if (Root == NULL)      
		return false;                     
    else if (k == Root->key)
	{ d1 = Root->country;
	  d2 = Root->latitude;
	  d3 = Root->longitude;
	  d4 = Root->longitude2;
	  d5 = Root->latitude2;
	  d6 = Root->dlat;
	  d7 = Root->dlon;
	 return true;} 
    else if (k < Root->key)
		return retrieve2(Root->left, k, d1, d2, d3, d4, d5,d6,d7); 
    else
		return retrieve2(Root->right,k, d1, d2, d3, d4, d5,d6,d7); 
}
template <class keytype, class datatype>
void BST <keytype, datatype> :: preorder (treenode* Root) const
{
   if (empty())
      return;

  cout << Root->data << " ";
  preorder (Root ->left);
  preorder (Root ->right);
   
}
template <class keytype, class datatype>
void BST <keytype, datatype> :: levelorder () const
{
 	Queuet<treenode*> q;
	treenode* t = root;
	q.enqueue(t);
	while(!q.queueIsEmpty())
	{
		q.dequeue(t); cout << t->key << endl;
		if ( t->left  != NULL ) q.enqueue (t->left);
		if ( t->right != NULL ) q.enqueue (t->right);
	}
}
template <class keytype, class datatype>
void BST <keytype, datatype> :: remove (const keytype &k)
{
  	bool found;
	treenode* x,parent;

	parentSearch (k, found, x, parent);
	if (!found)
	{
		cout << "Item not in BST\n";
		return;
	}

	if ((x->left != NULL)&&(x->right != NULL))
	{	
		treenode* xSucc = x->right;
		parent = x;
		while (xSucc->left != NULL) 
		{ parent = xSucc; xSucc = xSucc->left; }
	
		x->key = xSucc->key; x->data = xSucc->data;
		x = xSucc;
	} 

	treenode* subtree = x->left; 
	if (subtree == NULL) subtree = x->right;
	if (parent == NULL) root = subtree;
	else if (parent->left == x) 
		parent->left = subtree;
	else parent->right = subtree; 
	delete x;
}
template <class keytype, class dataType>
void BST <keytype, dataType>::parentSearch (const keytype &k, bool &found, treenode* &locptr, treenode* &parent) const
                                                                              
{
	locptr = root;  parent = NULL; found = false;
	while (!found && locptr != NULL)
	{
		if (k < locptr->key)
		{
			parent = locptr;	locptr = locptr->left;
		}
		else if (locptr->key < k)
		{
			parent = locptr;	locptr = locptr->right;
		}
		else found = true; 
	}
}
template <class keytype, class dataType>
void BST <keytype, dataType>::save_to_file(ofstream &file, treenode* root)
{
	if (root == NULL)
		return;
	
	save_to_file(file, root-> left);

	file << root-> key << " " << root-> latitude << " " <<<< root-> latitude2 << root->longitude << root->longitude2 << " " << root-> country << endl;

	save_to_file(file, root-> right);


}
template <class keytype, class dataType>
void BST <keytype, dataType>::load_from_file(string& filename)
{
    ifstream input;
	string city,country;
	double lat,lon,lat2,lon2;
	char d1,d2;
	input.open(filename.c_str());
	while (input >> city >>  lat >> lat2 >> d1>> lon >> lon2 >> d2 >> country >>)
	{
		insert(root, city, country, lat,lon,lon2,lat2,d1,d2);
	}
}
template <class keytype, class dataType>
void BST <keytype, dataType>:: save(treenode* root, string& filename)
{
	ofstream file(filename);

    save_to_file(root, file);
}
template <class keytype, class dataType>
double  BST <keytype, dataType> :: compute(keytype k1, keytype k2)
{ 				
		
		string d1,d11;
		double d2,d21;
		double d3,d31;
		double d4,d41;
		double d5,d51;
		char d6,d61;
		char d7,d71;
		/*string country_name;
		double latitude2;
		double latitude;
		double longitude;
		double longitude2;
		char dlat;
		char dlon;*/
retrieve(root, k1, d1, d2, d3, d4, d5,d6,d7);
retrieve(root, k2, d11, d21, d31, d41, d51,d61,d71);
calculateDistance(d3,d2,d4,d5,d31,d21,d41,d51,d6,d61,d7,d71);

}
template <class keytype, class dataType>
double BST <keytype, dataType> ::convertToRadians(double degrees, double minutes, char x)
	{
    double decimalDegrees = degrees + (minutes / 60);
    double radians = decimalDegrees * PI/ 180;
	if ( x == 'S' || x == 'W') {
        radians = -radians;
	}
    return radians;
}


template <class keytype, class dataType>
double BST <keytype, dataType> :: calculateDistance(double lat1,double lat11,double lon1, double lon11, double lat2,double lat21, double lon2,double lon21,char X,char X2, char Y, char Y2) {

    double phi1 = convertToRadians(lat1, lat11, X);
    double phi2 = convertToRadians(lat2, lat21, X2);
    double lambda1 = convertToRadians(lon1, lon11, Y);
    double lambda2 = convertToRadians(lon2, lon21, Y2);


    double deltaPhi = phi2 - phi1;
    double deltaLambda = lambda2 - lambda1;


    double a = sin(deltaPhi / 2) * sin(deltaPhi / 2) +
               cos(phi1) * cos(phi2) * sin(deltaLambda / 2) * sin(deltaLambda / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double R = 6371.137;

    double distance = R * c;
    return distance;
}