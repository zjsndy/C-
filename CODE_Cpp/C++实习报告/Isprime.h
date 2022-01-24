#pragma once
#ifndef ISPRIME
#define ISPRIME
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<math.h>
#define mem(a,x) memset(a,x,sizeof(a);
typedef long long LL;
const int maxn = 50005;
const int mod = 26;
const int INF = 0x3f3f3f3f;
const int Times = 10;
const int N = 5500;

using namespace std;

LL gcd(LL a, LL b); //�������������

LL multi(LL a, LL b, LL m); //���ٳ�
LL pow(LL a, LL b, LL m); //������

bool Miller_Rabin(LL n); //�ж��ǲ�������

#endif // !ISPRIME
