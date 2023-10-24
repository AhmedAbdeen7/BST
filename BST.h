
#include <string>
using namespace std;
#ifndef BST_H
#define BST_H
template <class keytype, class datatype>
class BST
{
 private:
     
	class treenode
	   {
		public:
		keytype key; 				
		treenode *left;		      
		treenode *right;
		string country_name;
		double latitude2;
		double latitude;
		double longitude;
		double longitude2;
		char dlat;
		char dlon;
	   }; 
      treenode *root;


 public:
      
		BST();

		bool insert (treenode &Root, const keytype &k, const keytype &d1, const datatype &d2, const datatype &d3,const datatype &d4, const datatype &d5,const datatype &d6, const datatype &d7);

		bool empty() const;

		bool search (const keytype &, treenode*) const;

		bool retrieve (treenode* Root, const keytype &k, keytype &d1, datatype &d2, datatype &d3, datatype &d4,  datatype &d5,const datatype &d6, const datatype &d7) const
		
		void traverse() const;

		void preorder (treenode* Root) const;

		void levelorder () const;

		void remove (const keytype &);

		void parentSearch (const keytype &k, bool &found, treenode* &locptr, treenode* &parent) const;
                                                                       
		void save_to_file(ofstream& file, treenode* root);

		void load_from_file(string& filename);

		void  save(treenode* root, string& filename);

		double compute(keytype k1, keytype k2);

		double convertToRadians(double degrees, double minutes, char x);
		double calculateDistance(double lat1,double lat11,double lon1, double lon11, double lat2,double lat21, double lon2,double lon21,char X,char X2, char Y, char Y2)





};



#endif