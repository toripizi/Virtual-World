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
	const int numberOfBarszcz = 0;
	const int numberOfWilczeJagody = 0;
	const int numberOfGuarana = 0;
	const int numberOfMlecz = 3;
	const int numberOfTrawa = 3;
	const int numberOfOwca = 0;
	const int numberOfLis = 2;
	const int numberOfWilk = 0;
	const int numberOfZolw = 0;
	const int numberOfAntylopa = 0;

	for (int i = 0; i < numberOfBarszcz; i++) {
		new BarszczSosnowskiego;
	}

	for (int i = 0; i < numberOfWilczeJagody; i++) {
		new WilczeJagody;
	}

	for (int i = 0; i < numberOfGuarana; i++) {
		new Guarana;
	}

	for (int i = 0; i < numberOfMlecz; i++) {
		new Mlecz;
	}

	for (int i = 0; i < numberOfTrawa; i++) {
		new Trawa;
	}

	for (int i = 0; i < numberOfOwca; i++) {
		new Owca;
	}

	for (int i = 0; i < numberOfLis; i++) {
		new Lis;
	}

	for (int i = 0; i < numberOfWilk; i++) {
		new Wilk;
	}

	for (int i = 0; i < numberOfZolw; i++) {
		new Zolw;
	}

	for (int i = 0; i < numberOfAntylopa; i++) {
		new Antylopa;
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
	//otwieram plik
	ofstream save("saves.txt", ios::binary | std::ios::trunc);
	if (save.is_open()) {
		//zapisuje szerokosc i wysokosc
		save.write((char*)&this->width, sizeof(int));
		save.write((char*)&this->height, sizeof(int));

		//tworze strukture tymczasow¹ File
		File* file = new File;
		Node* temporary = world.organisms.first;
		vector<File> vec{};

		file->x = temporary->getOrganism()->getX();
		file->y = temporary->getOrganism()->getY();
		file->name = temporary->getOrganism()->getName();
		vec.push_back(*file);
		//wpycham struktore do vektora

		while (temporary != world.organisms.last) {
			temporary = temporary->getNext();
			file->x = temporary->getOrganism()->getX();
			file->y = temporary->getOrganism()->getY();
			file->name = temporary->getOrganism()->getName();
			vec.push_back(*file);
			//wpycham struktore do vektora
		}
		int size = vec.size() * sizeof(File);
		save.write((char*)vec.data(), size);
		save.close();
		delete file;
	}
	
}

const int World::getHumanX() {
	return humanX;
}
const int World::getHumanY() {
	return humanY;
}

