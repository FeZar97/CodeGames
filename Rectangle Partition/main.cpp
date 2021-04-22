#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void fillSizes(vector<int> &sizes, int coordinatesNb, int maxCoordinate) {
	sizes[0] = 0;

	for(int i = 1; i < coordinatesNb - 1; i++) {
		cin >> sizes[i];
	}

	sizes[sizes.size() - 1] = maxCoordinate;
}

void getAvailableSizes(map<int, int> &availableSizes, const vector<int> &coordinates) {

	for(int coordinateIdx = 0; coordinateIdx < coordinates.size() - 1; coordinateIdx++) {
		int curCoordinate = coordinates[coordinateIdx];

		for(int nextCoordinateIdx = coordinateIdx + 1; nextCoordinateIdx < coordinates.size(); nextCoordinateIdx++) {
			int nextCoordinate = coordinates[nextCoordinateIdx];
			++availableSizes[nextCoordinate - curCoordinate];
		}
	}
}

int main() {
	int width, height, xCoordNb, yCoordNb;
	cin >> width >> height >> xCoordNb >> yCoordNb;
	cin.ignore();

	vector<int> xCoordinates(xCoordNb + 2), yCoordinates(yCoordNb + 2);

	fillSizes(xCoordinates, xCoordNb + 2, width);
	fillSizes(yCoordinates, yCoordNb + 2, height);

	map<int, int> availableWidths, availableHeights;
	getAvailableSizes(availableWidths, xCoordinates);
	getAvailableSizes(availableHeights, yCoordinates);

	int squaresNb = 0;
	for(const auto &availWidthPair: availableWidths) {

		int curWidth = availWidthPair.first;

		if(availableHeights.count(curWidth)) {
			squaresNb += availWidthPair.second * availableHeights[curWidth];
		}
	}

	cout << squaresNb << endl;
}
