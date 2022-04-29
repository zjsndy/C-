#include "statement.h"

//右旋
void R_Rotate(BBSTree *p)
{
    BBSTNode *LC;

    LC = (*p)->LChild;
    (*p)->LChild = LC->RChild;
    LC->RChild = *p;
    *p = LC;
}

//左旋
void L_Rotate(BBSTree *p)
{
    BBSTNode *RC;

    RC = (*p)->RChild;
    (*p)->RChild = RC->LChild;
    RC->LChild = *p;
    *p = RC;
}

void LeftBalance(BBSTree *T)
{
    BBSTNode *LC, *RD;

    LC = (*T)->LChild;

    switch (LC->bf)
    {
    case LH:         //新节点插入在*T左孩子的左子树上(LL)
        (*T)->bf = LC->bf = EH;
        R_Rotate(T);
        break;
    case RH:         //新节点插入在*T左孩子右子树上(LR)
        RD = LC->RChild;
        switch (RD->bf)
        {
        case LH:
            (*T)->bf = RH;
            LC->bf = EH;
            break;
        case EH:
            (*T)->bf = LC->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            LC->bf = LH;
            break;
        }
        RD->bf = EH;
        L_Rotate(&(*T)->LChild);
        R_Rotate(T);
        break;
    }
}

void RightBalance(BBSTree *T)
{
    BBSTNode *RC, *LD;

    RC = (*T)->RChild;

    switch (RC->bf)
    {
    case RH:
        (*T)->bf = RC->bf = EH;           //新节点插在右孩子的右子树上(RR)
        L_Rotate(T);
        break;
    case LH:                       //右孩子的左子树上(RL)
        LD = RC->LChild;
        switch (LD->bf)
        {
        case LH:
            (*T)->bf = EH;
            RC->bf = RH;
            break;
        case EH:
            (*T)->bf = RC->bf = EH;
            break;
        case RH:
            (*T)->bf = LH;
            RC->bf = EH;
            break;
        }
        LD->bf = EH;
        R_Rotate(&(*T)->RChild);
        L_Rotate(T);
        break;
    }
}

int InsertAVL(BBSTree *T,int e,Boolean *taller)
{
    if(!(*T))
    {
        *T = (BBSTree)malloc(sizeof(BBSTNode));
        (*T)->data = e;
        (*T)->LChild = (*T)->RChild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if(EQ(e,(*T)->data))    //若树中已存在和e有相同关键字的结点,则不再插入
        {
            *taller = FALSE;
            return 0;
        }
        else if(LT(e,(*T)->data))   //搜索左子树
        {
           if(!InsertAVL(&(*T)->LChild,e,taller))
               return 0;                     //未插入

            if(*taller)
            {
                switch ((*T)->bf)
                {
                case LH:         //插入前左子树高于右子树,需做左平衡处理
                    LeftBalance(T);
                    *taller = FALSE;
                    break;
                case EH:           //插入前左子树等高于右子树,现左子树增高
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH:              //插入前右子树高于左子树,现左右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
            }
        }
        else                   //搜寻右子树
        {
            if(!InsertAVL(&(*T)->RChild,e,taller))       //未插入
                return 0;
            
            if(*taller)                //已插入到右子树,且右子树"长高"
            {
                switch((*T)->bf)
                {
                    case LH:       //插入前左子树高于右子树,现左右子树等高
                        (*T)->bf = EH;
                        *taller = FALSE;
                        break;
                    case EH:           //插入前左右子树等高，现右子树"增高"
                        (*T)->bf = RH;
                        *taller = TRUE;
                        break;
                    case RH:         //插入前右子树高于左子树,需做右平衡处理
                        RightBalance(T);
                        *taller = FALSE;
                        break;
                }
            }
        }
    }
    return 1;
}

int CreateAVL(BBSTree *T,FILE *fp)
{
    int i, t,len,tmp;
    char c;

    *T = NULL;
    t = FALSE;

    fscanf(fp, "%d", &len);
    fscanf(fp, "%c", &c);

    if(len)
    {
        for (i = 1; i <= len;i++)
        {
            fscanf(fp, "%d", &tmp);
            InsertAVL(T, tmp, &t);
        }
    }

    return 1;
}

//p指向当前结点,f指向p的父节点，初始化为空，*taller初始化为FALSE，mark代表f与p的关系，初始化为0
int DeleteAVL(BBSTree *T,int e,BBSTree f,BBSTree p,Boolean *taller,int mark)
{
    BBSTNode *r;
    int tmp;
    
    if(!p)
        return 0;
    else
    {
        if(LT(e,p->data))           //关键字较小,搜寻左子树
        {
            if(!DeleteAVL(T,e,p,p->LChild,taller,0))
                return 0;

            if(*taller)
            {
                switch (p->bf)
                {
                case LH:
                    p->bf = EH;
                    *taller = TRUE;
                    break;
                case EH:
                    p->bf = RH;
                    *taller = FALSE;
                    break;
                case RH:
                    if(!f)
                        RightBalance(T);
                    else
                        RightBalance(&(f->LChild));

                    *taller = TRUE;
                    break;
                }
            }
        }
        else if(RT(e,p->data))        //关键字较大,搜寻右子树
        {
            if(!DeleteAVL(T,e,p,p->RChild,taller,1))
                return 0;

            if(*taller)
            {
                switch (p->bf)
                {
                case LH:
                    if(!f)
                        LeftBalance(T);
                    else
                        LeftBalance(&(f->RChild));
                    *taller = TRUE;
                    break;
                case EH:
                    p->bf = LH;
                    *taller = FALSE;
                    break;
                case RH:
                    p->bf = EH;
                    *taller = TRUE;
                    break;
                }
            }
        }
        else                 //找到关键词
        {
            if(p->LChild!=NULL&&p->RChild==NULL)    //只有左子树
            {
                if(!f)
                    *T = p->LChild;
                else
                {
                    if(mark==0)
                        f->LChild = p->LChild;
                    else
                        f->RChild = p->LChild;
                }

                free(p);
                p = NULL;

                *taller = TRUE;
            }
            else if(p->LChild==NULL&&p->RChild!=NULL)      //只有右子树
            {
                if(!f)
                    *T = p->RChild;
                else
                {
                    if(mark==0)
                        f->LChild = p->RChild;
                    else
                        f->RChild = p->RChild;
                }

                free(p);
                p = NULL;

                *taller = TRUE;
            }
            else if(p->LChild==NULL&&p->RChild==NULL)         //左右子树为空
            {
                if(!f)
                    *T = NULL;
                else
                {
                    if(mark==0)
                        f->LChild = NULL;
                    else
                        f->RChild = NULL;
                }

                free(p);
                p = NULL;

                *taller = TRUE;
            }
            else                             //左右子树均不空
            {
                r = p->LChild;

                while(r->RChild)
                    r = r->RChild;

                tmp = r->data;

                *taller = FALSE;
                if(!f)
                    DeleteAVL(T, tmp, NULL, p, taller, mark);
                else
                {
                    if(mark==0)
                        DeleteAVL(&(f->LChild), tmp, NULL, p, taller, mark);
                    else
                        DeleteAVL(&(f->RChild), tmp, NULL, p, taller, mark);
                }
                p->data = tmp;
            }
        }

        return 1;   
    }
}