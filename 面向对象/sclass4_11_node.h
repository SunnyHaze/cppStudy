#ifndef _SCLASS4_11_NODE_H_
#define _SCLASS4_11_NODE_H_

#include <iostream>
#include <string>
using namespace std;

const int LEN = 20;
class CNodeArray;

class CNode{
    friend CNodeArray; //��ΪҪ����ȡ��Ԫ��������ǰ��ֱ�������� ָ�����顣
    friend ostream& operator << (ostream& cout,CNode& obj);
    friend istream& operator >> (istream& cin ,CNode& obj);
    static int sNodeNum;

public:
    CNode(string str);                          //���캯��
    CNode(const CNode &oCN);                    //��������
    virtual ~CNode();                           //��������
    CNode &operator = (const CNode &oCN);       //���ظ�ֵ�����
    const CNode &operator , (const CNode &oCN); //���ض��������
    int GetNumber(void);                        //���ص�ǰsNodeNum����������1��
    string *GetStr();                           //����ָ��ڵ����ֵ��ַ���ָ��
    int &GetNodeNum();                          //���ؽڵ�ı��
private:
    string *m_pStr;
    int m_nodeNum;
};
//**********************************************
//�����ڵ������࣬�����ڹ����ڶ�ڵ㣬�������ݳ�Ա�ͺ�����Ա�����Ҫ���ڷ������
// �ڶ�ڵ����Ҫ��Ϊ�˲����򵥣��ڱ����������һ������ΪLEN��ָ�����飬���ݵ�ÿһ����Ա������ָ��
// һ��CNode�ڵ���󣬵�ϵͳ����һ���ڵ��Ժ󣬾͸���m_aIndexȷ���ڵ��������е�λ�ã����ڵ����ٺ�Ҳ�������ջ�
// �����Ӧ��Ԫ��ָ���������ã���ϰʱ��Ӧ�����¼����Ƕ���չ��
// 1�����ǻ��սڵ�ɾ�����ָ���������á�
// 2���������һ���Ƚ�С�����飨�糤��Ϊ26����Ȼ���սڵ����ֵ�����ĸ��ͬ��Ӧ����ڲ�ͬ������ָ��λ�ã���������ĸ��ͬ�Ľڵ㰴������ʽ
// ��������
// 3���������ܵ���չ������������Ŀ����Ҫ���ڷ���۲�����ִ�й��̡�
//*******************************************************
class CNodeArray{
    friend CNode;
public:
    CNodeArray(int alenth = LEN);       //���캯����Ĭ�����鳤��ΪLEN��
    virtual ~CNodeArray(void);          //����������
    CNode operator [] (int i);          //���� ��������
    void* operator new (size_t size);   //���� new
    void operator delete(void *p);      //����delete
    bool Insert(CNode &obj);            //�������в���һ���ڵ�
    bool Delete(int index);             //��������ɾ��һ���ڵ�
private:
    CNode *m_poCN[LEN];
    int m_aLenth;
    int m_aIndex;
};
#endif