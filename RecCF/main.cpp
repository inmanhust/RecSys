#include <iostream>
#include "RecInterface.h"
#include "CfKernel.h"
#include "Cf.h"

using namespace std;
using namespace RecSys;

int main()
{
	cout << "start---->"<< endl;
	CF cf;
	cf.loadIndex("../data/u.data");
	//cf.writeIndexToBibaryFile("../data/binary_index");
	cf.loadIndexFromBinaryFile("../data/binary_index");
	//cf.loadIndex("../data/new_ratings.dat");
	cf.loadReverseIndex();
	//cf.print();
	unordered_map<uint32_t,vector<Entity> >& index = cf.user_index_;
	cf.getNeighbors(index[1], 0.3, 10);
//	printf("done\n");
//	sleep(1000000);
	cout << "end---->"<< endl;
	return 0;	
}
