#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

//enum�� �� ���� �ϳ� ����صδ°��� �����ϴ�.
//�߰� �Ǵ� ������ ���ܵ� enum�� �� ���� �ϳ� �� �з����� ������ control flow�� �����ϱ� ��������.

enum MAIN_MENU
{
	MM_NONR,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_INN,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_RUNAWAY,
	BATTLE_END
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

enum EQUIP
{
	EQ_NONE,
	EQ_WEAPONE,
	EQ_ARMOR,
	EQ_BACK
};

#define NAME_SIZE 20
#define ITEM_DESCRIPTION 514
#define INVENTORY_SIZE 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define EQ_MAX 3

struct _gameItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE type;
	int min;
	int max;
	int price;
	int sell;
	char strDesc[ITEM_DESCRIPTION];
};

struct _gameInventory
{
	_gameItem item[INVENTORY_SIZE];
	int itemCount;
	int gold;
};

struct _gamePlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB eJob;	//strJobName�� strcmp�� ���ϱ⿡�� �ð��� �����ɸ���, ������ index�� ������ �������ش�.

	int attackMin;
	int attackMax;
	int armorMin;
	int armorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int Exp;
	int Level;
	int LevelUpExp = 1000;
	struct _gameItem equipItem[EQ_MAX];
	bool isEquiped[EQ_MAX] = { false };
	struct _gameInventory inventory;
};

struct _gameMonster
{
	char strName[NAME_SIZE];
	int attackMin;
	int attackMax;
	int armorMin;
	int armorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int Level;
	int dropExp;
	int dropGoldMin;
	int dropGoldMax;
	

};


using namespace std;
int main()
{
	srand((unsigned int)time(0));

	/*������ �����Ҷ� �÷��̾� ������ ����*/
	_gamePlayer player = {};

	cout << "Name: ";
	cin.getline(player.strName, NAME_SIZE - 1);
	int selMenu;
	int selJob = JOB_NONE;
	while (selJob == JOB_NONE)
	{
		system("cls");
		cout << "1.Knight" << endl;
		cout << "2.Archer" << endl;
		cout << "3.Wizard" << endl;
		cout << "������ �����Ͻÿ�: ";
		cin >> selJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (selJob == JOB_NONE || selJob >= JOB_END)
		{
			selJob = JOB_NONE;
		}

		player.Level = 1;
		player.Exp = 0;
		player.inventory.gold = 10000;
		
		player.eJob = (JOB)selJob;

		switch (player.eJob)
		{
		case JOB_KNIGHT:
			strcpy(player.strJobName, "Knight");
			player.attackMin = 5;
			player.attackMax = 10;
			player.armorMin = 15;
			player.armorMax = 20;
			player.HP = 500;
			player.HPMax = 500;
			player.MP = 100;
			player.MPMax = 100;
			break;

		case JOB_ARCHER:
			strcpy(player.strJobName, "Archer");
			player.attackMin = 15;
			player.attackMax = 20;
			player.armorMin = 10;
			player.armorMax = 15;
			player.HP = 400;
			player.HPMax = 400;
			player.MP = 200;
			player.MPMax = 200;
			break;

		case JOB_WIZARD:
			strcpy(player.strJobName, "Wizard");
			player.attackMin = 25;
			player.attackMax = 30;
			player.armorMin = 5;
			player.armorMax = 10;
			player.HP = 200;
			player.HPMax = 200;
			player.MP = 400;
			player.MPMax = 400;
			break;

		default:

			break;
		}
	
	}

	/*���� ����*/
	_gameMonster monsterArr[MT_BACK - 1] = {}; 

	//��� ����
	strcpy(monsterArr[0].strName, "Goblin");
	monsterArr[0].attackMin = 20;
	monsterArr[0].attackMax = 30;
	monsterArr[0].armorMin = 2;
	monsterArr[0].armorMax = 4;
	monsterArr[0].HP = 100;
	monsterArr[0].HPMax = 100;
	monsterArr[0].MP = 10;
	monsterArr[0].MPMax = 10;
	monsterArr[0].dropGoldMax = 1000;
	monsterArr[0].dropGoldMin = 500;
	monsterArr[0].Level = 1;
	monsterArr[0].dropExp = 1000;

	//��ũ ����
	strcpy(monsterArr[1].strName, "Ork");
	monsterArr[1].attackMin = 40;
	monsterArr[1].attackMax = 60;
	monsterArr[1].armorMin = 10;
	monsterArr[1].armorMax = 15;
	monsterArr[1].HP = 1000;
	monsterArr[1].HPMax = 1000;
	monsterArr[1].MP = 10;
	monsterArr[1].MPMax = 10;
	monsterArr[1].dropGoldMax = 3000;
	monsterArr[1].dropGoldMin = 2500;
	monsterArr[1].Level = 5;
	monsterArr[1].dropExp = 5000;

	//����� ����
	strcpy(monsterArr[2].strName, "Ork");
	monsterArr[2].attackMin = 140;
	monsterArr[2].attackMax = 260;
	monsterArr[2].armorMin = 100;
	monsterArr[2].armorMax = 150;
	monsterArr[2].HP = 10000;
	monsterArr[2].HPMax = 10000;
	monsterArr[2].MP = 100;
	monsterArr[2].MPMax = 100;
	monsterArr[2].dropGoldMax = 13000;
	monsterArr[2].dropGoldMin = 12500;
	monsterArr[2].Level = 10;
	monsterArr[2].dropExp = 25000;

	/*�Ǹ��� ������ ��� ����*/
	_gameItem storeWeapon[STORE_WEAPON_MAX] = {};
	_gameItem storeArmor[STORE_ARMOR_MAX] = {};

	storeWeapon[0] = { "��Į", "Weapon", IT_WEAPON, 5, 8, 1000, 100, "�ֹ濡 �ִ� Į" };
	storeWeapon[1] = { "������ �����", "Weapon", IT_WEAPON, 15, 28, 10000, 1000, "���ù����� ������" };
	storeWeapon[2] = { "���̾�� ��������", "Weapon", IT_WEAPON, 105, 208, 100000, 10000, "���۸�ó�� ������" };

	storeArmor[0] = { "��Ƽ", "Weapon", IT_ARMOR, 5, 8, 1000, 100, "����Ŭ�� ��Ƽ" };
	storeArmor[1] = { "���װ���", "Weapon", IT_ARMOR, 15, 28, 10000, 1000, "�Ұ���" };
	storeArmor[2] = { "���̾�� ��Ʈ", "Weapon", IT_ARMOR, 105, 208, 100000, 10000, "���۸�ó�� ưư������" };

	/*main Lobby*/
	while (true)
	{
		system("cls");
		cout << "-------------------Main Lobby-----------------" << endl;
		cout << "1.��" << endl;
		cout << "2.����" << endl;
		cout << "3.����" << endl;
		cout << "4.�޽�" << endl;
		cout << "5.����" << endl;
		cout << "�޴��� �����ϼ���: ";
		
		cin >> selMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (selMenu == MM_EXIT)
		{
			break;
		}

		switch (selMenu)
		{
		case MM_MAP:

			while (true)
			{
				system("cls");
				cout << "-------------------Map-----------------" << endl;
				cout << "1.EASY" << endl;
				cout << "2.NORMAL" << endl;
				cout << "3.HARD" << endl;
				cout << "4.Back" << endl;
				cout << "���� �����ϼ���: ";
				int selMap;
				cin >> selMap;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (selMap == MT_BACK)
				{
					break;
				}

				/*������ ���� number -1�� monsater�� type�� �ȴ�. */
				int monsterType = selMap - 1;
				_gameMonster monster = {};
				monster = monsterArr[monsterType];


				int selAct;
				bool isMonsterDead = false;
				bool isPlayerDead = false;
				while (true) {
					system("cls");
					if (isMonsterDead || isPlayerDead) {
						while (player.LevelUpExp <= player.Exp)
						{
							player.Level += 1;
							cout << "Level Up!!!!!" << endl;
							cout << "Level: " << player.Level << endl;
							player.LevelUpExp *= 2;
							if (player.eJob == JOB_KNIGHT)
							{
								player.attackMax *= 1.2;
								player.attackMin *= 1.2;
								player.armorMax *= 2;
								player.armorMin *= 2;
								player.HPMax *= 2;
								player.MPMax *= 1.2;
							}
							else if (player.eJob == JOB_ARCHER)
							{
								player.attackMax *= 1.5;
								player.attackMin *= 1.5;
								player.armorMax *= 1.5;
								player.armorMin *= 1.5;
								player.HPMax *= 1.5;
								player.MPMax *= 1.5;
							}
							else if (player.eJob == JOB_WIZARD)
							{
								player.attackMax *= 2;
								player.attackMin *= 2;
								player.armorMax *= 1.2;
								player.armorMin *= 1.2;
								player.HPMax *= 1.2;
								player.MPMax *= 2;
							}
						}

						break;
					}
					switch (selMenu)
					{
					case MT_EASY:
						cout << "*****************Easy*****************" << endl;
						break;

					case MT_NORMAL:
						cout << "*****************Normal*****************" << endl;
						break;

					case MT_HARD:
						cout << "*****************Hard*****************" << endl;
						break;
					}

					/*Player ���� ���*/
					cout << "=====================Player=====================" << endl;
					cout << "Name: " << player.strName << "\tJob: " << player.strJobName << endl;
					cout << "Level: " << player.Level << "\tExp: " << player.Exp << "/" << player.LevelUpExp << endl;

					if (player.isEquiped[EQ_WEAPONE])
					{
						cout << "Attack: " << player.attackMin << "+" << player.equipItem[EQ_WEAPONE].min << " ~  " << player.attackMax << "+" << player.equipItem[EQ_WEAPONE].max << endl;
					}
					else
					{
						cout << "Attack: " << player.attackMin << " ~ " << player.attackMax << endl;
					}
					if (player.isEquiped[EQ_ARMOR])
					{
						cout << "Defence: " << player.armorMin << "+" << player.equipItem[EQ_ARMOR].min << " ~  " << player.armorMin << "+" << player.equipItem[EQ_ARMOR].max << endl;
					}
					else
					{
						cout << "Defence: " << player.armorMin << " ~ " << player.armorMin << endl;
					}
					cout << "Hp: " << player.HP << "/" << player.HPMax << "\tMP: " << player.MP << "/" << player.MPMax << endl;
					cout << "Gold: " << player.inventory.gold << endl;

					/*Monster ���� ���*/
					cout << "=====================Monster=====================" << endl;
					cout << "Name: " << monster.strName << endl;
					cout << "Level: " << monster.Level << endl;
					cout << "Attack: " << monster.attackMin << " ~ " << monster.attackMax << endl;
					cout << "Deffence: " << monster.armorMin << " ~ " << monster.armorMax << endl;
					cout << "Hp: " << monster.HP << "/" << monster.HPMax << "\tMP: " << monster.MP << "/" << monster.MPMax << endl;
					cout << "DropExp: " << monster.dropExp << endl;
					cout << "Dropgold: " << monster.dropGoldMin << " ~ " << monster.dropGoldMax << endl;


					cout << "=================================================" << endl;
					cout << "1.Attack" << endl;
					cout << "2. Run Away" << endl;
					cout << "�ൿ ����: ";
					cin >> selAct;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (selAct == BATTLE_RUNAWAY)
					{
						break;
					}

					switch (selAct)
					{
					case BATTLE_ATTACK:
						//player�� Attack ��
						int attackMax = player.attackMax + player.equipItem[EQ_WEAPONE].max;
						int attackMin = player.attackMin + player.equipItem[EQ_WEAPONE].min;
						int attack = rand() % (attackMax - attackMin + 1) + attackMin;

						//monster�� armor ��
						int armor = rand() % (monster.armorMax - monster.armorMin + 1) + monster.armorMin;

						int damage = attack - armor;
						damage = damage < 1 ? 1 : damage;

						/*monster hp ����*/
						monster.HP -= damage;

						cout << player.strName << " attcked " << damage << "point to " << monster.strName << endl;

						/*if monster ����*/
						if (monster.HP <= 0)
						{
							cout << monster.strName << " monster  DEAD" << endl;
							player.Exp += monster.dropExp;
							int gold = rand() % (monster.dropGoldMax - monster.dropGoldMin + 1) + monster.dropGoldMin;
							player.inventory.gold += gold;

							cout << monster.dropExp << " EXP ȹ��" << endl;
							cout << gold << " GOLD ȹ��" << endl;

							isMonsterDead = true;
							monster.HP = monster.HPMax;
							monster.MP = monster.MPMax;
						}
						/*monster ����*/
						else
						{
							int attack = rand() % (monster.attackMax - monster.attackMin + 1) + monster.attackMin;
							
							int armorMax = player.armorMax + player.equipItem[EQ_ARMOR].max;
							int armorMin = player.armorMin + player.equipItem[EQ_ARMOR].min;
							int armor = rand() % (armorMax - armorMin + 1) + armorMin;

							int damage = attack - armor;
							damage = damage < 1 ? 1 : damage;

							/*player hp ����*/
							player.HP -= damage;

							cout << monster.strName << " attcked " << damage << "point to " << player.strName << endl;

							/*player ���*/
							if (player.HP <= 0)
							{
								cout << player.strName << " player  DEAD" << endl;
								int exp = player.Exp*0.1;
								int gold = player.inventory.gold * 0.1;
								player.Exp -= exp;
								player.inventory.gold -= gold;

								cout << exp << " EXP ����" << endl;
								cout << gold << " GOLD ����" << endl;

								isPlayerDead = true;
								player.HP = player.HPMax;
								player.MP = player.MPMax;
							}

						}

						system("pause");
						break;
					}

				}

			}
			break;

		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "1. ���� ����" << endl;
				cout << "2. �� ����" << endl;
				cout << "3. �ڷ� ����" << endl;
				cout << "������ �����ϼ���: ";
				cin >> selMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (selMenu == SM_BACK)
				{
					break;
				}
				int selItem;
				switch (selMenu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");

						cout << "============================�������=============================" << endl;
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". " << storeWeapon[i].strName << endl;
							cout << "�ǸŰ���: " << storeWeapon[i].price << endl;
							cout << "���ݷ�: " << storeWeapon[i].min << " ~ " << storeWeapon[i].max << endl << endl;
						}
						cout << STORE_WEAPON_MAX + 1 << ". " << "�ڷΰ���" << endl;
						cout << "__________________________________________________________________" << endl;
						cout << "���� Gold: " << player.inventory.gold << " Gold" << endl;
						cout << "��������: " << INVENTORY_SIZE - player.inventory.itemCount << endl;

						cout << "������ �������� �����ϼ���: ";

						cin >> selItem;
						selItem -= 1;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (selItem == STORE_WEAPON_MAX)
						{
							break;
						}
						int gold = player.inventory.gold - storeWeapon[selItem].price;
						int itemCount = player.inventory.itemCount + 1;
						if (gold < 0)
						{
							cout << "Gold ����!!" << endl;
							system("pause");
							continue;
						}
						else if (itemCount > INVENTORY_SIZE)
						{
							cout << "Inventory ���� ����!!" << endl;
							system("pause");
							continue;
						}
						player.inventory.itemCount = itemCount;
						player.inventory.gold = gold;
						cout << storeWeapon[selItem].strName << "�� �����Ͽ����ϴ�." << endl;
						cout << "���� Gold: " << player.inventory.gold << "gold" << endl;
						cout << "��������: " << INVENTORY_SIZE - player.inventory.itemCount << endl;
						cout << "__________________________________________________________________" << endl;
						/*player.attackMax += storeWeapon[selItem].max;
						player.attackMin += storeWeapon[selItem].min;*/
						player.inventory.item[itemCount - 1] = storeWeapon[selItem];

						system("pause");
						break;

					}
					break;
				case SM_ARMOR:
					while (true)
					{
						system("cls");

						cout << "============================�� ����=============================" << endl;
						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". " << storeArmor[i].strName << endl;
							cout << "�ǸŰ���: " << storeArmor[i].price << endl;
							cout << "����: " << storeArmor[i].min << " ~ " << storeArmor[i].max << endl << endl;
						}
						cout << STORE_ARMOR_MAX + 1<< ". " << "�ڷΰ���" << endl;
						cout << "__________________________________________________________________" << endl;
						cout << "���� Gold: " << player.inventory.gold << " Gold" << endl;
						cout << "��������: " << INVENTORY_SIZE - player.inventory.itemCount << endl;

						cout << "������ �������� �����ϼ���: ";
						cin >> selItem;
						selItem -= 1;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (selItem == STORE_ARMOR_MAX)
						{
							break;
						}
						int gold = player.inventory.gold - storeArmor[selItem].price;
						int itemCount = player.inventory.itemCount + 1;
						if (gold < 0)
						{
							cout << "Gold ����!!" << endl;
							system("pause");
							continue;
						}
						else if (itemCount > INVENTORY_SIZE)
						{
							cout << "Inventory ���� ����!!" << endl;
							system("pause");
							continue;
						}
						player.inventory.itemCount = itemCount;
						player.inventory.gold = gold;
						cout << storeArmor[selItem].strName << "�� �����Ͽ����ϴ�." << endl;
						cout << "���� Gold: " << player.inventory.gold << "gold" << endl;
						cout << "__________________________________________________________________" << endl;
						/*player.armorMax += storeArmor[selItem].max;
						player.armorMin += storeArmor[selItem].min;*/
						player.inventory.item[itemCount - 1] = storeArmor[selItem];
						system("pause");
						break;
					}
					break;
				}

			}
			break;

		case MM_INVENTORY:
			while (true)
			{
				system("cls");
				cout << "=====================Player=====================" << endl;
				cout << "Name: " << player.strName << "\tJob: " << player.strJobName << endl;
				cout << "Level: " << player.Level << "\tExp: " << player.Exp <<"/"<<player.LevelUpExp<< endl;

				//������ �������� �ɷ�ġ�� �����Ͽ� ���
				if (player.isEquiped[EQ_WEAPONE])
				{
					cout << "Attack: " << player.attackMin << "+" << player.equipItem[EQ_WEAPONE].min << " ~  " << player.attackMax << "+" << player.equipItem[EQ_WEAPONE].max << endl;
				}
				else
				{
					cout << "Attack: " << player.attackMin << " ~ " << player.attackMax << endl;
				}
				if (player.isEquiped[EQ_ARMOR])
				{
					cout << "Defence: " << player.armorMin << "+" << player.equipItem[EQ_ARMOR].min << " ~  " << player.armorMin << "+" << player.equipItem[EQ_ARMOR].max << endl;
				}
				else
				{
					cout << "Defence: " << player.armorMin << " ~ " << player.armorMin << endl;
				}

				cout << "Hp: " << player.HP << "/" << player.HPMax << "\tMP: " << player.MP << "/" << player.MPMax << endl;
				cout << "Gold: " << player.inventory.gold << endl;
				cout << "___________________________________________________" << endl;
				cout << "Equiped List" << endl;
				for (int i = 0; i < EQ_MAX; i++)
				{
					if (player.isEquiped[i])
					{
						cout << player.equipItem[i].strName << endl;
					}
				}

				cout << "___________________________________________________" << endl;
				cout << "Inventory List" << endl;
				for (int i = 0; i < player.inventory.itemCount; i++)
				{
					cout << i + 1 << ". " << player.inventory.item[i].strName << endl;
				}
				cout << player.inventory.itemCount + 1 << ". �ڷ� ����" << endl;
				cout << "������ �������� �����ϼ���: ";
				cin >> selMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (selMenu == player.inventory.itemCount + 1)
				{
					break;
				}

				/*���⸦ �����ϰ� �ִ���, �ƴ��� ���� ����Ͽ� ����*/
				EQUIP eq;
				int selectItem = selMenu - 1;
				switch (player.inventory.item[selectItem].type)
				{
				case IT_WEAPON:
					eq = EQ_WEAPONE;
					break;

				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				//�ش� �������� Ÿ���� �����Ǿ��ִ����� ������ ���� flow
				//Swap �˰��� �̿�
				if (player.isEquiped[eq])
				{
					_gameItem temp = player.equipItem[eq];
					player.equipItem[eq] = player.inventory.item[selectItem];
					player.inventory.item[selectItem] = temp;
				}
				else
				{
					player.equipItem[eq] = player.inventory.item[selectItem];

					//�κ��丮���� �������� ������ �޺κ� array�� ��ĭ�� �������.
					for (int i = selectItem; i < player.inventory.itemCount - 1; i++)
					{
						player.inventory.item[i] = player.inventory.item[i + 1];
					}
					player.inventory.itemCount--;

					//������ �Ǿ����Ƿ� �ش� ������ Ÿ���� ���� ������ true�� �ʱ�ȭ
					player.isEquiped[eq] = true;
				}
				cout << player.equipItem[eq].strName << " �������� �����Ͽ����ϴ�." << endl;
				system("pause");
			}
			break;

		case MM_INN:
			while (true)
			{
				system("cls");
				cout << "INN �޽��Ͻðڽ��ϱ� (��� 1000��)" << endl;
				cout << "���� Gold: " << player.inventory.gold << endl;
				cout << "1. ��           2. �ƴϿ�" << endl;
				cin >> selMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (selMenu == 2)
				{
					break;
				}
				if (selMenu == 1) {
					int gold = player.inventory.gold - 1000;
					if (gold < 0)
					{
						cout << "Gold ����!!" << endl;
						system("pause");
						continue;
					}
					
					cout << "---------�޽���----------" << endl;
					int HP = player.HP + player.HPMax*0.3;
					int MP = player.MP + player.MPMax*0.3;
					if (HP > player.HPMax || MP > player.MPMax)
					{
						player.HP = player.HPMax;
						player.MP = player.MPMax;
						cout << "�޽��� �� �ʿ����� �ʽ��ϴ�. " << endl;
						system("pause");
						continue;
					}
					player.inventory.gold = gold;
					player.HP += player.HPMax*0.3;
					player.MP += player.MPMax*0.3;
					
					cout << "HP�� " << player.HP << "/" << player.HPMax << "ȸ��" << endl;
					cout << "MP�� " << player.MP << "/" << player.MPMax << "ȸ��" << endl;
					system("pause");
				}
			}
			break;

		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;

		}
	}

	return 0;
}