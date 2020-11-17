def matrix_split(M,l):
    l=int(l/2)
    a = [ [ 0 for i in range(l) ] for j in range(l) ]
    b = [ [ 0 for i in range(l) ] for j in range(l) ]
    c = [ [ 0 for i in range(l) ] for j in range(l) ]
    d = [ [ 0 for i in range(l) ] for j in range(l) ]

    for i in range(l):
        for j in range(l):
            a[i][j]=M[i][j]
            b[i][j]=M[i][j+l]
            c[i][j]=M[i+l][j]
            d[i][j]=M[i+l][j+l]

    return a,b,c,d
     
def add(m,n,l):
    if l == 1:
        return m+n

    else:
        d=[ [ 0 for i in range(l) ] for j in range(l) ]

        for i in range(l):
            for j in range (l):
                d[i][j]=m[i][j]+n[i][j]

        return d

def sub(m,n,l):
    if l == 1:
        return m-n

    else:
        s=[ [ 0 for i in range(l) ] for j in range(l) ]

        for i in range(l):
            for j in range (l):
                s[i][j]=m[i][j]-n[i][j]

        return s
    

def Strassen_mat_mul(A,B,n):
    if n==2:
        ans = [ [ 0 for i in range(2) ] for j in range(2) ]
        ans[0][0]=A[0][0]*B[0][0] + A[0][1]*B[1][0]
        ans[0][1]=A[0][0]*B[0][1] + A[0][1]*B[1][1]
        ans[1][0]=A[1][0]*B[0][0] + A[1][1]*B[1][0]
        ans[1][1]=A[1][0]*B[0][1] + A[1][1]*B[1][1]
        return ans

    else:
        l=int(n/2)
        a11,a12,a21,a22= matrix_split(A,n)
        b11, b12, b21, b22= matrix_split(B,n)

        p= Strassen_mat_mul(add(a11,a22,l),add(b11,b22,l),l)
        q= Strassen_mat_mul(add(a21,a22,l),b11,l)
        r= Strassen_mat_mul(a11,sub(b12,b22,l),l)
        s= Strassen_mat_mul(a22,sub(b21,b11,l),l)
        t= Strassen_mat_mul(add(a11,a12,l),b22,l)
        u= Strassen_mat_mul(sub(a21,a11,l),add(b11,b12,l),l)
        v= Strassen_mat_mul(sub(a12,a22,l),add(b21,b22,l),l)

        c11=add(sub(add(p,s,l),t,l),v,l)
        c12=add(r,t,l)
        c21=add(q,s,l)
        c22=add(sub(add(p,r,l),q,l),u,l)

        c=[ [ 0 for i in range(n) ] for j in range(n) ]

        for i in range(l):
            for j in range(l):
                c[i][j]=c11[i][j]
                c[i][j+l]=c12[i][j]
                c[i+l][j]=c21[i][j]
                c[i+l][j+l]=c22[i][j]

        return c

a = [[1,1,3,5],[2,9,2,0],[3,1,5,9],[4,8,5,7]]
b = [[5,0,5,1],[6,3,5,2],[7,2,6,11],[8,14,20,3]]
print ("Multiplication of:",a)
print(b)
print("Result:")
print (Strassen_mat_mul(a, b, 4))
