#include "animals.cpp"
#include "Plants.cpp"
#include <vector>
#include <string>

World::World(int H, int W) : height(H), width(W) {
	srand((unsigned)time(NULL));
}

void World::initTab() {
	tab = new Square * [width];
	for (int i = 0; i < width; i++) {
		tab[i] = new Square[height];
	}
}
World::~World() {
	for (int i = 0; i < width; i++) {
		delete[] tab[i];
	}
}

void World::init() {
	const int numberOfBarszcz = 1;
	const int numberOfWilczeJagody = 1;
	const int numberOfGuarana = 200;
	const int numberOfMlecz = 1;
	const int numberOfTrawa = 1;
	const int numberOfOwca = 1;
	const int numberOfLis = 1;
	const int numberOfWilk = 9;
	const int numberOfZolw = 1;
	const int numberOfAntylopa = 20;

	BarszczSosnowskiego* barszcz[numberOfBarszcz]{};
	for (int i = 0; i < numberOfBarszcz; i++) {
		barszcz[i] = new BarszczSosnowskiego;
	}

	WilczeJagody* jagody[numberOfWilczeJagody]{};
	for (int i = 0; i < numberOfWilczeJagody; i++) {
		jagody[i] = new WilczeJagody;
	}

	Guarana* guarana[numberOfGuarana]{};
	for (int i = 0; i < numberOfGuarana; i++) {
		guarana[i] = new Guarana;
	}

	Mlecz* mlecz[numberOfMlecz]{};
	for (int i = 0; i < numberOfMlecz; i++) {
		mlecz[i] = new Mlecz;
	}

	Trawa* trawa[numberOfTrawa]{};
	for (int i = 0; i < numberOfTrawa; i++) {
		trawa[i] = new Trawa;
	}

	Owca* owca[numberOfOwca]{};
	for (int i = 0; i < numberOfOwca; i++) {
		owca[i] = new Owca;
	}

	Lis* lis[numberOfLis]{};
	for (int i = 0; i < numberOfLis; i++) {
		lis[i] = new Lis;
	}

	Wilk* wilk[numberOfWilk]{};
	for (int i = 0; i < numberOfWilk; i++) {
		wilk[i] = new Wilk;
	}

	Zolw* zolw[numberOfZolw]{};
	for (int i = 0; i < numberOfZolw; i++) {
		zolw[i] = new Zolw;
	}

	Antylopa* antylopa[numberOfAntylopa]{};
	for (int i = 0; i < numberOfAntylopa; i++) {
		antylopa[i] = new Antylopa;
	}
}

//World::~World();
const int World::getHeight() {
	return height;
}

const int World::getWidth() {
	return width;
}

void World::drawWorld() {
	cout << "C - czlowiek | ";
	cout << "W - wilk | ";
	cout << "O - owca | ";
	cout << "L - lis | ";
	cout << "Z - zolw | ";
	cout << "A - antylopa | " << endl;

	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 2; j++) {
			if(i == 0 || i == height + 1 || j == 0 || j == width + 1) {
				std::cout << (char)219;
				std::cout << (char)219;
			}
			else {
				tab[j - 1][i - 1].display();
			}
		}
		std::cout << std::endl;
	}
}

void World::setGameOver() {
	gameOver = true;
}

const bool World::getGameOver(){
	return gameOver;
}

void World::nextTurn() {
	world.organisms.MAKE_ACTION();
}

void World::loadWorldFromFile() {
	ifstream ifs("saves.txt", ios::binary | ios::in);
	ifs.read((char*)&width, sizeof(int));
	ifs.read((char*)&height, sizeof(int));

	world.initTab();

	File* temp = new File;
	while(ifs.read((char*)temp, sizeof(File))){
		if (temp->name == "wilk") {
			new Wilk(temp->x, temp->y);
		}
		else if (temp->name == "owca") {
			new Owca(temp->x, temp->y);
		}
		else if (temp->name == "lis") {
			new Lis(temp->x, temp->y);
		}
		else if (temp->name == "zolw") {
			new Zolw(temp->x, temp->y);
		}
		else if (temp->name == "antylopa") {
			new Antylopa(temp->x, temp->y);
		}
		else if (temp->name == "trawa") {
			new Trawa(temp->x, temp->y);
		}
		else if (temp->name == "mlecz") {
			new Mlecz(temp->x, temp->y);
		}
		else if (temp->name == "guarana") {
			new Guarana(temp->x, temp->y);
		}
		else if (temp->name == "wilcze jagody") {
			new WilczeJagody(temp->x, temp->y);
		}
		else if (temp->name == "barszcz") {
			new BarszczSosnowskiego(temp->x, temp->y);
		}
		else if (temp->name == "human") {
			humanX = temp->x;
			humanY = temp->y;
		}
	}
	ifs.close();
}
void World::writeWorldToFile() {
	vector<File> vec{};
	ofstream save1("saves.txt", ios::binary | std::ios::trunc);
	if (save1.is_open()) {
		save1.write((char*)&this->width, sizeof(int));
		save1.write((char*)&this->height, sizeof(int));
		save1.close();
	}
	

	ofstream save("saves.txt", ios::binary | ios::app);

	File* file = new File;

	Node* temporary = world.organisms.first;
	
	file->x = temporary->getOrganism()->getX();
	file->y = temporary->getOrganism()->getY();
	file->name = temporary->getOrganism()->getName();
	vec.push_back(*file);
	while (temporary != world.organisms.last) {
		temporary = temporary->getNext();
		file->x = temporary->getOrganism()->getX();
		file->y = temporary->getOrganism()->getY();
		file->name = temporary->getOrganism()->getName();
		vec.push_back(*file);
	}
	int size = vec.size() * sizeof(File);
	save.write((char*)vec.data(), size);
	delete file;
	save.close();
}

const int World::getHumanX() {
	return humanX;
}
const int World::getHumanY() {
	return humanY;
}

