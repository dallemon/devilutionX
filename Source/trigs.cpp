//HEADER_GOES_HERE

#include "../types.h"

int trigflag[MAXTRIGGERS];
TriggerStruct trigs[MAXTRIGGERS];
int TWarpFrom; // weak

int TownDownList[11] = { 716, 715, 719, 720, 721, 723, 724, 725, 726, 727, -1 };
int TownWarp1List[13] = {
	1171,
	1172,
	1173,
	1174,
	1175,
	1176,
	1177,
	1178,
	1179,
	1181,
	1183,
	1185,
	-1
};
int L1UpList[12] = { 127, 129, 130, 131, 132, 133, 135, 137, 138, 139, 140, -1 };
int L1DownList[10] = { 106, 107, 108, 109, 110, 112, 114, 115, 118, -1 };
int L2UpList[3] = { 266, 267, -1 };
int L2DownList[5] = { 269, 270, 271, 272, -1 };
int L2TWarpUpList[3] = { 558, 559, -1 };
int L3UpList[15] = {
	170,
	171,
	172,
	173,
	174,
	175,
	176,
	177,
	178,
	179,
	180,
	181,
	182,
	183,
	-1
};
int L3DownList[9] = { 162, 163, 164, 165, 166, 167, 168, 169, -1 };
int L3TWarpUpList[14] = { 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, -1 };
int L4UpList[4] = { 82, 83, 90, -1 };
int L4DownList[6] = { 120, 130, 131, 132, 133, -1 };
int L4TWarpUpList[4] = { 421, 422, 429, -1 };
int L4PentaList[33] = {
	353,
	354,
	355,
	356,
	357,
	358,
	359,
	360,
	361,
	362,
	363,
	364,
	365,
	366,
	367,
	368,
	369,
	370,
	371,
	372,
	373,
	374,
	375,
	376,
	377,
	378,
	379,
	380,
	381,
	382,
	383,
	384,
	-1
};

void InitNoTriggers()
{
	trigflag[4] = 0;
	trigflag[3] = 0;
}

void InitTownTriggers()
{
	char v0; // bl
	int v1;  // eax
	int v2;  // eax

	trigs[0]._tx = 25;
	trigs[0]._ty = 29;
	trigs[0]._tmsg = WM_DIABNEXTLVL;
	trigflag[4] = 1;
	if (gbMaxPlayers == 4) {
		trigs[1]._tx = 49;
		trigflag[0] = 1;
		trigflag[1] = 1;
		trigflag[2] = 1;
		trigs[1]._ty = 21;
		trigs[1]._tmsg = WM_DIABTOWNWARP;
		trigs[1]._tlvl = 5;
		trigs[2]._tx = 17;
		trigs[2]._ty = 69;
		trigs[2]._tmsg = WM_DIABTOWNWARP;
		trigs[2]._tlvl = 9;
		trigs[3]._tx = 41;
		trigs[3]._ty = 80;
		trigs[3]._tmsg = WM_DIABTOWNWARP;
		trigs[3]._tlvl = 13;
		trigflag[4] = 4;
	} else {
		trigflag[0] = 0;
		trigflag[1] = 0;
		trigflag[2] = 0;
		v0 = plr[myplr].pTownWarps;
		if (v0 & 1) {
			trigs[1]._tx = 49;
			trigs[1]._ty = 21;
			trigs[1]._tmsg = WM_DIABTOWNWARP;
			trigs[1]._tlvl = 5;
			trigflag[4] = 2;
			trigflag[0] = 1;
		}
		if (v0 & 2) {
			trigflag[1] = 1;
			v1 = trigflag[4]++;
			trigs[v1]._tx = 17;
			trigs[v1]._ty = 69;
			trigs[v1]._tmsg = WM_DIABTOWNWARP;
			trigs[v1]._tlvl = 9;
		}
		if (v0 & 4) {
			trigflag[2] = 1;
			v2 = trigflag[4]++;
			trigs[v2]._tx = 41;
			trigs[v2]._ty = 80;
			trigs[v2]._tmsg = WM_DIABTOWNWARP;
			trigs[v2]._tlvl = 13;
		}
	}
	trigflag[3] = 0;
}
// 679660: using guessed type char gbMaxPlayers;

void InitL1Triggers()
{
	int j, i;
	int *_tmsg, *_ty, *_tx;

	trigflag[4] = 0;
	for (j = 0; j < MAXDUNY; j++) {
		i = 0;
		_tmsg = &trigs[trigflag[4]]._tmsg;
		_ty = &trigs[trigflag[4]]._ty;
		_tx = &trigs[trigflag[4]]._tx;
		while (i < MAXDUNX) {
			if (dPiece[i][j] == 129) {
				trigflag[4]++;
				*_tx = i;
				*_ty = j;
				*_tmsg = WM_DIABPREVLVL;
				_tx += sizeof(int *);
				_ty += sizeof(int *);
				_tmsg += sizeof(int *);
			}
			if (dPiece[i][j] == 115) {
				trigflag[4]++;
				*_tx = i;
				*_ty = j;
				*_tmsg = WM_DIABNEXTLVL;
				_tx += sizeof(int *);
				_ty += sizeof(int *);
				_tmsg += sizeof(int *);
			}
			i++;
		}
	}
	trigflag[3] = 0;
}

void InitL2Triggers()
{
	signed int v0;     // edi
	int *v1;           // esi
	int *v2;           // edx
	TriggerStruct *v3; // ecx
	int *v4;           // eax
	int(*v5)[112];     // [esp+Ch] [ebp-10h]
	int(*v6)[112];     // [esp+10h] [ebp-Ch]
	int v7;            // [esp+14h] [ebp-8h]
	int *v8;           // [esp+18h] [ebp-4h]

	trigflag[4] = 0;
	v7 = 0;
	v5 = dPiece;
	do {
		v0 = 0;
		v1 = &trigs[trigflag[4]]._tmsg;
		v2 = &trigs[trigflag[4]]._ty;
		v3 = &trigs[trigflag[4]];
		v8 = &trigs[trigflag[4]]._tlvl;
		v6 = v5;
		do {
			if ((*v6)[0] == 267 && (v0 != quests[QTYPE_BONE]._qtx || v7 != quests[QTYPE_BONE]._qty)) {
				++trigflag[4];
				v8 += 4;
				v3->_tx = v0;
				*v2 = v7;
				*v1 = WM_DIABPREVLVL;
				++v3;
				v2 += 4;
				v1 += 4;
			}
			if ((*v6)[0] == 559) {
				v3->_tx = v0;
				*v2 = v7;
				v4 = v8;
				v8 += 4;
				*v1 = WM_DIABTWARPUP;
				*v4 = 0;
				++trigflag[4];
				++v3;
				v2 += 4;
				v1 += 4;
			}
			if ((*v6)[0] == 271) {
				++trigflag[4];
				v8 += 4;
				v3->_tx = v0;
				*v2 = v7;
				*v1 = WM_DIABNEXTLVL;
				++v3;
				v2 += 4;
				v1 += 4;
			}
			++v6;
			++v0;
		} while (v0 < 112);
		v5 = (int(*)[112])((char *)v5 + 4);
		++v7;
	} while ((signed int)v5 < (signed int)dPiece[1]);
	trigflag[3] = 0;
}

void InitL3Triggers()
{
	int v0;            // edi
	signed int v1;     // esi
	int *v2;           // edx
	int *v3;           // ecx
	TriggerStruct *v4; // eax
	int(*v5)[112];     // [esp+Ch] [ebp-8h]
	int(*v6)[112];     // [esp+10h] [ebp-4h]

	v0 = 0;
	trigflag[4] = 0;
	v5 = dPiece;
	do {
		v1 = 0;
		v6 = v5;
		v2 = &trigs[trigflag[4]]._tmsg;
		v3 = &trigs[trigflag[4]]._ty;
		v4 = &trigs[trigflag[4]];
		do {
			if ((*v6)[0] == 171) {
				++trigflag[4];
				v4->_tx = v1;
				*v3 = v0;
				*v2 = WM_DIABPREVLVL;
				++v4;
				v3 += 4;
				v2 += 4;
			}
			if ((*v6)[0] == 168) {
				++trigflag[4];
				v4->_tx = v1;
				*v3 = v0;
				*v2 = WM_DIABNEXTLVL;
				++v4;
				v3 += 4;
				v2 += 4;
			}
			if ((*v6)[0] == 549) {
				++trigflag[4];
				v4->_tx = v1;
				*v3 = v0;
				*v2 = WM_DIABTWARPUP;
				++v4;
				v3 += 4;
				v2 += 4;
			}
			++v6;
			++v1;
		} while (v1 < 112);
		v5 = (int(*)[112])((char *)v5 + 4);
		++v0;
	} while ((signed int)v5 < (signed int)dPiece[1]);
	trigflag[3] = 0;
}

void InitL4Triggers()
{
	signed int v0;     // edi
	int *v1;           // esi
	int *v2;           // edx
	TriggerStruct *v3; // ecx
	int *v4;           // eax
	int v5;            // edx
	int(*v6)[112];     // edi
	signed int v7;     // ecx
	int *v8;           // eax
	int(*v9)[112];     // [esp+Ch] [ebp-Ch]
	int(*v10)[112];    // [esp+Ch] [ebp-Ch]
	int v11;           // [esp+10h] [ebp-8h]
	int(*v12)[112];    // [esp+14h] [ebp-4h]

	trigflag[4] = 0;
	v11 = 0;
	v9 = dPiece;
	do {
		v0 = 0;
		v12 = v9;
		v1 = &trigs[trigflag[4]]._tmsg;
		v2 = &trigs[trigflag[4]]._ty;
		v3 = &trigs[trigflag[4]];
		v4 = &trigs[trigflag[4]]._tlvl;
		do {
			if ((*v12)[0] == 83) {
				++trigflag[4];
				v3->_tx = v0;
				*v2 = v11;
				*v1 = WM_DIABPREVLVL;
				v4 += 4;
				++v3;
				v2 += 4;
				v1 += 4;
			}
			if ((*v12)[0] == 422) {
				v3->_tx = v0;
				*v2 = v11;
				*v1 = WM_DIABTWARPUP;
				*v4 = 0;
				++trigflag[4];
				v4 += 4;
				++v3;
				v2 += 4;
				v1 += 4;
			}
			if ((*v12)[0] == 120) {
				++trigflag[4];
				v3->_tx = v0;
				*v2 = v11;
				*v1 = WM_DIABNEXTLVL;
				v4 += 4;
				++v3;
				v2 += 4;
				v1 += 4;
			}
			++v12;
			++v0;
		} while (v0 < 112);
		v9 = (int(*)[112])((char *)v9 + 4);
		++v11;
	} while ((signed int)v9 < (signed int)dPiece[1]);
	v5 = 0;
	v10 = dPiece;
	do {
		v6 = v10;
		v7 = 0;
		v8 = &trigs[trigflag[4]]._ty;
		do {
			if ((*v6)[0] == 370 && quests[QTYPE_VB]._qactive == 3) {
				++trigflag[4];
				*(v8 - 1) = v7;
				*v8 = v5;
				v8[1] = WM_DIABNEXTLVL;
				v8 += 4;
			}
			++v7;
			++v6;
		} while (v7 < 112);
		v10 = (int(*)[112])((char *)v10 + 4);
		++v5;
	} while ((signed int)v10 < (signed int)dPiece[1]);
	trigflag[3] = 0;
}

void InitSKingTriggers()
{
	trigflag[3] = 0;
	trigflag[4] = 1;
	trigs[0]._tx = 82;
	trigs[0]._ty = 42;
	trigs[0]._tmsg = WM_DIABRTNLVL;
}

void InitSChambTriggers()
{
	trigflag[3] = 0;
	trigflag[4] = 1;
	trigs[0]._tx = 70;
	trigs[0]._ty = 39;
	trigs[0]._tmsg = WM_DIABRTNLVL;
}

void InitPWaterTriggers()
{
	trigflag[3] = 0;
	trigflag[4] = 1;
	trigs[0]._tx = 30;
	trigs[0]._ty = 83;
	trigs[0]._tmsg = WM_DIABRTNLVL;
}

void InitVPTriggers()
{
	trigflag[3] = 0;
	trigflag[4] = 1;
	trigs[0]._tx = 35;
	trigs[0]._ty = 32;
	trigs[0]._tmsg = WM_DIABRTNLVL;
}

BOOL ForceTownTrig()
{
	int i, j, k, l;

	for (i = 0; TownDownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == TownDownList[i]) {
			strcpy(infostr, "Down to dungeon");
			cursmx = 25;
			cursmy = 29;
			return TRUE;
		}
	}

	if (trigflag[0]) {
		for (j = 0; TownWarp1List[j] != -1; j++) {
			if (dPiece[cursmx][cursmy] == TownWarp1List[j]) {
				strcpy(infostr, "Down to catacombs");
				cursmx = 49;
				cursmy = 21;
				return TRUE;
			}
		}
	}

	if (trigflag[1]) {
		for (k = 1199; k <= 1220; k++) {
			if (dPiece[cursmx][cursmy] == k) {
				strcpy(infostr, "Down to caves");
				cursmx = 17;
				cursmy = 69;
				return TRUE;
			}
		}
	}

	if (trigflag[2]) {
		for (l = 1240; l <= 1254; l++) {
			if (dPiece[cursmx][cursmy] == l) {
				strcpy(infostr, "Down to hell");
				cursmx = 41;
				cursmy = 80;
				return TRUE;
			}
		}
	}

	return FALSE;
}

BOOL ForceL1Trig()
{
	int i, j;

	for (i = 0; L1UpList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L1UpList[i]) {
			if (currlevel > 1)
				sprintf(infostr, "Up to level %i", currlevel - 1);
			else
				strcpy(infostr, "Up to town");
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABPREVLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	for (i = 0; L1DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L1DownList[i]) {
			sprintf(infostr, "Down to level %i", currlevel + 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABNEXTLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	return FALSE;
}

BOOL ForceL2Trig()
{
	int i, j, dx, dy;

	for (i = 0; L2UpList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L2UpList[i]) {
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABPREVLVL) {
					dx = abs(trigs[j]._tx - cursmx);
					dy = abs(trigs[j]._ty - cursmy);
					if (dx < 4 && dy < 4) {
						sprintf(infostr, "Up to level %i", currlevel - 1);
						cursmx = trigs[j]._tx;
						cursmy = trigs[j]._ty;
						return TRUE;
					}
				}
			}
		}
	}

	for (i = 0; L2DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L2DownList[i]) {
			sprintf(infostr, "Down to level %i", currlevel + 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABNEXTLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	if (currlevel == 5) {
		for (i = 0; L2TWarpUpList[i] != -1; i++) {
			if (dPiece[cursmx][cursmy] == L2TWarpUpList[i]) {
				for (j = 0; j < trigflag[4]; j++) {
					if (trigs[j]._tmsg == WM_DIABTWARPUP) {
						dx = abs(trigs[j]._tx - cursmx);
						dy = abs(trigs[j]._ty - cursmy);
						if (dx < 4 && dy < 4) {
							strcpy(infostr, "Up to town");
							cursmx = trigs[j]._tx;
							cursmy = trigs[j]._ty;
							return TRUE;
						}
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL ForceL3Trig()
{
	int i, j, dx, dy;

	for (i = 0; L3UpList[i] != -1; ++i) {
		if (dPiece[cursmx][cursmy] == L3UpList[i]) {
			sprintf(infostr, "Up to level %i", currlevel - 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABPREVLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	for (i = 0; L3DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L3DownList[i] || dPiece[cursmx + 1][cursmy] == L3DownList[i] || dPiece[cursmx + 2][cursmy] == L3DownList[i]) {
			sprintf(infostr, "Down to level %i", currlevel + 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABNEXTLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	if (currlevel == 9) {
		for (i = 0; L3TWarpUpList[i] != -1; i++) {
			if (dPiece[cursmx][cursmy] == L3TWarpUpList[i]) {
				for (j = 0; j < trigflag[4]; j++) {
					if (trigs[j]._tmsg == WM_DIABTWARPUP) {
						dx = abs(trigs[j]._tx - cursmx);
						dy = abs(trigs[j]._ty - cursmy);
						if (dx < 4 && dy < 4) {
							strcpy(infostr, "Up to town");
							cursmx = trigs[j]._tx;
							cursmy = trigs[j]._ty;
							return TRUE;
						}
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL ForceL4Trig()
{
	int i, j, dx, dy;

	for (i = 0; L4UpList[i] != -1; ++i) {
		if (dPiece[cursmx][cursmy] == L4UpList[i]) {
			sprintf(infostr, "Up to level %i", currlevel - 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABPREVLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	for (i = 0; L4DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L4DownList[i]) {
			sprintf(infostr, "Down to level %i", currlevel + 1);
			for (j = 0; j < trigflag[4]; j++) {
				if (trigs[j]._tmsg == WM_DIABNEXTLVL) {
					cursmx = trigs[j]._tx;
					cursmy = trigs[j]._ty;
					return TRUE;
				}
			}
		}
	}

	if (currlevel == 13) {
		for (i = 0; L4TWarpUpList[i] != -1; i++) {
			if (dPiece[cursmx][cursmy] == L4TWarpUpList[i]) {
				for (j = 0; j < trigflag[4]; j++) {
					if (trigs[j]._tmsg == WM_DIABTWARPUP) {
						dx = abs(trigs[j]._tx - cursmx);
						dy = abs(trigs[j]._ty - cursmy);
						if (dx < 4 && dy < 4) {
							strcpy(infostr, "Up to town");
							cursmx = trigs[j]._tx;
							cursmy = trigs[j]._ty;
							return TRUE;
						}
					}
				}
			}
		}
	}

	if (currlevel == 15) {
		for (i = 0; L4PentaList[i] != -1; i++) {
			if (dPiece[cursmx][cursmy] == L4PentaList[i]) {
				strcpy(infostr, "Down to Diablo");
				for (j = 0; j < trigflag[4]; j++) {
					if (trigs[j]._tmsg == WM_DIABNEXTLVL) {
						cursmx = trigs[j]._tx;
						cursmy = trigs[j]._ty;
						return TRUE;
					}
				}
			}
		}
	}

	return FALSE;
}

void Freeupstairs()
{
	int i, yy, xx, tx, ty;

	for (i = 0; i < trigflag[4]; i++) {
		tx = trigs[i]._tx;
		ty = trigs[i]._ty;

		for (yy = 0; yy < MAXTRIGGERS; yy++) {
			for (xx = 0; xx < MAXTRIGGERS; xx++) {
				dFlags[tx - 2 + xx][ty - 2 + yy] |= DFLAG_POPULATED;
			}
		}
	}
}

BOOL ForceSKingTrig()
{
	int i;

	for (i = 0; L1UpList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L1UpList[i]) {
			sprintf(infostr, "Back to Level %i", quests[QTYPE_KING]._qlevel);
			cursmx = trigs[0]._tx;
			cursmy = trigs[0]._ty;

			return TRUE;
		}
	}

	return FALSE;
}

BOOL ForceSChambTrig()
{
	int i;

	for (i = 0; L2DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L2DownList[i]) {
			sprintf(infostr, "Back to Level %i", quests[QTYPE_BONE]._qlevel);
			cursmx = trigs[0]._tx;
			cursmy = trigs[0]._ty;

			return TRUE;
		}
	}

	return FALSE;
}

BOOL ForcePWaterTrig()
{
	int i;

	for (i = 0; L3DownList[i] != -1; i++) {
		if (dPiece[cursmx][cursmy] == L3DownList[i]) {
			sprintf(infostr, "Back to Level %i", quests[QTYPE_PW]._qlevel);
			cursmx = trigs[0]._tx;
			cursmy = trigs[0]._ty;

			return TRUE;
		}
	}

	return FALSE;
}

void CheckTrigForce()
{
	int v0; // eax
	int v1; // eax

	trigflag[3] = 0;
	if (MouseY <= 351) {
		if (setlevel) {
			switch (setlvlnum) {
			case SL_SKELKING:
				v1 = ForceSKingTrig();
				break;
			case SL_BONECHAMB:
				v1 = ForceSChambTrig();
				break;
			case SL_POISONWATER:
				v1 = ForcePWaterTrig();
				break;
			default:
				return;
			}
			goto LABEL_23;
		}
		if (leveltype) {
			switch (leveltype) {
			case DTYPE_CATHEDRAL:
				v0 = ForceL1Trig();
				break;
			case DTYPE_CATACOMBS:
				v0 = ForceL2Trig();
				break;
			case DTYPE_CAVES:
				v0 = ForceL3Trig();
				break;
			case DTYPE_HELL:
				v0 = ForceL4Trig();
				break;
			default:
			LABEL_14:
				if (leveltype == DTYPE_TOWN)
					goto LABEL_24;
				if (trigflag[3]) {
				LABEL_25:
					ClearPanel();
					return;
				}
				v1 = ForceQuests();
			LABEL_23:
				trigflag[3] = v1;
			LABEL_24:
				if (!trigflag[3])
					return;
				goto LABEL_25;
			}
		} else {
			v0 = ForceTownTrig();
		}
		trigflag[3] = v0;
		goto LABEL_14;
	}
}
// 5CF31D: using guessed type char setlevel;

void CheckTriggers()
{
	int *v0;       // edi
	int v1;        // esi
	int v2;        // ecx
	int v3;        // eax
	int v4;        // edx
	signed int v5; // edx
	int v6;        // eax
	int v9;        // [esp-4h] [ebp-20h]
	int x;         // [esp+Ch] [ebp-10h]
	int y;         // [esp+10h] [ebp-Ch]
	int v12;       // [esp+14h] [ebp-8h]
	int error_id;  // [esp+1Bh] [ebp-1h]

	if (plr[myplr]._pmode)
		return;
	v12 = 0;
	if (trigflag[4] <= 0)
		return;
	v0 = &trigs[0]._tmsg;
	while (1) {
		v1 = myplr;
		v2 = plr[myplr].WorldX;
		if (v2 != *(v0 - 2))
			goto LABEL_34;
		v3 = plr[v1].WorldY;
		if (v3 != *(v0 - 1))
			goto LABEL_34;
		v4 = *v0;
		if (*v0 == WM_DIABNEXTLVL) {
			if (pcurs >= CURSOR_FIRSTITEM && DropItemBeforeTrig())
				return;
			v6 = currlevel + 1;
			goto LABEL_32;
		}
		if (*v0 == WM_DIABPREVLVL) {
			if (pcurs >= CURSOR_FIRSTITEM && DropItemBeforeTrig())
				return;
			v6 = currlevel - 1;
		LABEL_32:
			v9 = v6;
			goto LABEL_33;
		}
		if (*v0 != WM_DIABRTNLVL)
			break;
		StartNewLvl(myplr, v4, ReturnLvl);
	LABEL_34:
		++v12;
		v0 += 4;
		if (v12 >= trigflag[4])
			return;
	}
	if (*v0 != WM_DIABTOWNWARP) {
		if (*v0 == WM_DIABTWARPUP) {
			TWarpFrom = currlevel;
			StartNewLvl(myplr, v4, 0);
		} else {
			app_fatal("Unknown trigger msg");
		}
		goto LABEL_34;
	}
	if (gbMaxPlayers == 1)
		goto LABEL_46;
	v5 = 0;
	if (v0[1] == 5 && plr[v1]._pLevel < 8) {
		v5 = 1;
		x = plr[myplr].WorldX;
		_LOBYTE(y) = v3 + 1;
		_LOBYTE(error_id) = EMSG_REQUIRES_LVL_8;
	}
	if (v0[1] == 9 && plr[v1]._pLevel < 13) {
		v5 = 1;
		_LOBYTE(x) = v2 + 1;
		y = plr[v1].WorldY;
		_LOBYTE(error_id) = EMSG_REQUIRES_LVL_13;
	}
	if (v0[1] == 13 && plr[v1]._pLevel < 17) {
		x = plr[myplr].WorldX;
		v5 = 1;
		_LOBYTE(y) = v3 + 1;
		_LOBYTE(error_id) = EMSG_REQUIRES_LVL_17;
	}
	if (!v5) {
	LABEL_46:
		v9 = v0[1];
	LABEL_33:
		StartNewLvl(myplr, *v0, v9);
		goto LABEL_34;
	}
	switch (plr[myplr]._pClass) {
	case PC_WARRIOR:
		PlaySFX(PS_WARR43);
		break;
	case PC_ROGUE:
		PlaySFX(PS_ROGUE43);
		break;
	case PC_SORCERER:
		PlaySFX(PS_MAGE43);
		break;
	}
	_LOBYTE(v2) = error_id;
	InitDiabloMsg(v2);
	NetSendCmdLoc(TRUE, CMD_WALKXY, x, y);
}
// 679660: using guessed type char gbMaxPlayers;
// 6ABB30: using guessed type int TWarpFrom;
