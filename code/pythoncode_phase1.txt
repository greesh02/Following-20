import time
import serial
data = serial.Serial("com9 ",baudrate=9600)

# to the bot
initialx = 0
initialy = 0
first = 0
donew = 0

while True:
    k = 0
    P_vals = []
    fbrl = []
    uu = 0
    vv = 0
    vvv = 0

    prev_points = []
    jk = -2
    vall1 = []


    if first == 0:
        coor = input("enter x y coordinate: ").split()
        x = int(coor[0])
        y = int(coor[1])
        first = 1
        print(coor)
    elif first == 1:
        x = initialx
        y = initialy
        first = 2
        donew = 0
        print("now moving to the initial point : ",(x,y))
    else:
        print("done")
        break
    data.write(str(y).encode())
    print("entered y coordinate",data.readline().decode())

    time.sleep(2)

    data.write(str(x).encode())
    print("entered x coordinate", data.readline().decode())
    while True:




        while True:
            k += 1
            val = data.readline().decode()





            if k == 1:
                uu = int(val[0])
                print(uu,"uu")
                val = data.readline().decode()
                #if str(val)[1] == "x":
                   # val = data.readline().decode()
                    #vv = int(val[0])
                    #print(vv, "vv")
                #else:
                vv = int(val[0])
                print(vv, "vv")
                if vvv != 1:
                    xx = uu
                    yy = vv
                    prev_points.append((xx, yy))
                    print(prev_points,"the prev")
                if uu == x and vv == y:
                    donew = 1
                    break

            if k == 2:

                print("d -",val)
                val = data.readline().decode()

                bb = int(val)

                print(val)

                if bb == 100:
                    print(val)

                    if ( vv > 0):
                        mb = uu          # possible x coordinate // point behind the bot
                        nb = ( vv - 1)  # possible y coordinate
                        pb = (abs(x - mb) + abs(y - nb))
                    else :
                        pb = 700
                        mb = 101
                        nb = 101
                    if ( vv < 4):
                        mf = uu             #possible x // point front of the bot
                        nf = vv + 1            # possible y
                        pf = (abs(x - mf) + abs(y - nf))
                    else :
                        pf = 700
                        mf = 101
                        nf = 101
                    if ( uu > 0):
                        ml = (uu - 1)       # possible x // point left of the bot
                        nl = vv            # possible y
                        pl = (abs(x - ml) + abs(y - nl))
                    else :
                        pl = 700
                        ml = 101
                        nl = 101
                    if ( uu < 4) :
                        mr = (uu + 1)        # possible x // point right of the bot
                        nr = vv             # possible y
                        pr = (abs(x - mr) + abs(y - nr))
                    else :
                        pr = 700
                        mr = 101
                        nr = 101

                    fbrl = [(mf,nf),(mb,nb),(mr,nr),(ml,nl)]
                    print(fbrl,"f1")

                if bb == 200:

                    if (vv > 0):
                        mf = uu          # possible x // point front of the bot
                        nf = (vv - 1)     # possible y
                        pf = (abs(x - mf) + abs(y - nf))
                    else :
                        pf = 700
                        mf = 101
                        nf = 101
                    if (vv < 4):
                        mb = uu     # possible x // point behind the bot
                        nb = vv+1   # possible y
                        pb = (abs(x - mb) + abs(y - nb))
                    else :
                        pb = 700
                        mb = 101
                        nb = 101
                    if (uu > 0):
                        mr = uu - 1    # possible x // point right to bot
                        nr = vv        # possible y
                        pr = (abs(x - mr) + abs(y - nr))
                    else :
                        pr = 700
                        mr = 101
                        nr = 101
                    if (uu < 4):
                        ml = uu+1     # possible x // point left to bot
                        nl = vv        # possible y
                        pl = (abs(x - ml) + abs(y - nl))
                    else :
                        pl = 700
                        ml = 101
                        nl = 101

                    fbrl = [(mf, nf), (mb, nb), (mr, nr), (ml, nl)]
                    print(fbrl, "b1")

                if bb == 300:

                    if ( vv > 0):
                        mr = uu # possible x // point right of the bot
                        nr = (vv - 1) # possible y
                        pr = (abs(x - mr) + abs(y - nr))
                    else :
                        pr = 700
                        mr = 101
                        nr = 101
                    if (vv < 4):
                        ml = uu # possible x // point left to the bot
                        nl = vv+1 # possible y
                        pl = (abs(x - ml) + abs(y - nl))
                    else :
                        pl = 700
                        ml = 101
                        nl = 101
                    if ( uu > 0):
                        mb = uu - 1 # possible x // point behind the bot
                        nb = vv # possible y
                        pb = (abs(x - mb) + abs(y - nb))
                    else :
                        pb = 700
                        mb = 101
                        nb = 101
                    if ( uu < 4):
                         mf = uu+1 # possible x // point front to bot
                         nf = vv # possible y
                         pf = (abs(x - mf) + abs(y - nf))
                    else :
                        pf = 700
                        mf = 101
                        nf = 101

                    fbrl = [(mf, nf), (mb, nb), (mr, nr), (ml, nl)]
                    print(fbrl, "r1")

                if bb == 400:

                    if (vv > 0):
                        ml = uu # possible x coordinate // point left to the bot
                        nl = ( vv - 1) # possible y coordinate
                        pl = (abs(x - ml) + abs(y - nl))
                    else :
                        pl = 700
                        ml = 101
                        nl = 101
                    if (vv < 4):
                        mr = uu # possible x // point right of the bot
                        nr = vv+1 # possible y
                        pr = (abs(x - mr) + abs(y - nr))
                    else :
                        pr = 700
                        mr = 101
                        nr = 101
                    if (uu > 0):
                        mf = (uu - 1) # possible x // point front of the bot
                        nf = vv # possible y
                        pf = (abs(x - mf) + abs(y - nf))
                    else :
                        pf = 700
                        mf = 101
                        nf = 101
                    if (uu < 4) :
                        mb = (uu + 1) # possible x // point behind of the bot
                        nb = vv # possible y
                        pb = (abs(x - mb) + abs(y - nb))
                    else :
                        pb = 700
                        mb = 101
                        nb = 101

                    fbrl = [(mf, nf), (mb, nb), (mr, nr), (ml, nl)]
                    print(fbrl, "l1")






            if k == 3:
                print(val)


            if k > 3:
                print(val)
                P_vals.append(int(val))


            if k%7 == 0:
                print("_"*10)
                break
        k = 0

        if donew == 1:
            break


        while True:
            print(P_vals)
            minimum = P_vals[0]
            min_index = 0
            k1 = 0
            for i in P_vals:

                if i < minimum:
                    minimum = P_vals[k1]
                    min_index = k1
                k1 += 1


            print(min_index,"min_index")

            if  (P_vals == [700,700,700,700]) or ((P_vals[0:3] == [700,700,700]) and ((mb,nb)  in prev_points)):
                print(prev_points)

                print("getting into the safe zone")                                # fbrl = [(mf, nf), (mb, nb), (mr, nr), (ml, nl)]
                old  = prev_points[jk]
                print(jk, "jk")
                jk = jk - 2
                if old == fbrl[0]:
                    data.write(str.encode("1"))
                    print("pf ---------------------")
                    val1 = data.readline().decode()
                    if int(val1) == 1:
                        uu = uu
                        vv = vv
                        vvv = 1
                    else:
                        uu = mf
                        vv = nf
                        vvv = 0
                    break
                if old == fbrl[1]:
                    data.write(str.encode("3"))
                    print("pb ---------------------")
                    val1 = data.readline().decode()
                    if int(val1) == 1:
                        uu = uu
                        vv = vv
                        vvv = 1
                    else:
                        uu = mb
                        vv = nb
                        vvv = 0
                    break
                if old == fbrl[2]:
                    data.write(str.encode("0"))
                    print("pr ---------------------")
                    val1 = data.readline().decode()
                    if int(val1) == 1:
                        uu = uu
                        vv = vv
                        vvv = 1
                    else:
                        uu = mr
                        vv = nr
                        vvv = 0
                    break
                if old == fbrl[3]:
                    data.write(str.encode("2"))
                    print("pl ---------------------")
                    val1 = data.readline().decode()
                    if int(val1) == 1:
                        uu = uu
                        vv = vv
                        vvv = 1
                    else:
                        uu = ml
                        vv = nl
                        vvv = 0
                    break



            else:

                if min_index == 0:
                    if (mf,nf)  in prev_points:
                        P_vals[0] = 700
                    else:
                        jk = -2
                        data.write(str.encode("1"))
                        print("pf ---------------------")
                        val1 = data.readline().decode()
                        if int(val1) == 1:
                            uu = uu
                            vv = vv
                            P_vals[0] = 700
                            vvv = 1
                        else:
                            uu = mf
                            vv = nf
                            vvv = 0
                        break
                if min_index == 1:
                    if (ml,nl)  in prev_points:
                        P_vals[1] = 700
                    else:
                        jk = -2
                        data.write(str.encode("2"))
                        print("pl ---------------------")
                        val1 = data.readline().decode()
                        if int(val1) == 1:
                            uu = uu
                            vv = vv
                            P_vals[1] = 700
                            vvv = 1
                        else:
                            uu = ml
                            vv = nl
                            vvv = 0
                        break
                if min_index == 2:
                    if (mr,nr)  in prev_points:
                        P_vals[2] = 700
                    else:
                        jk = -2
                        data.write(str.encode("0"))
                        print("pr ---------------------")
                        val1 = data.readline().decode()
                        if int(val1) == 1:
                            uu = uu
                            vv = vv
                            P_vals[2] = 700
                            vvv = 1
                        else:
                            uu = mr
                            vv = nr
                            vvv = 0
                        break
                if min_index == 3:
                    if (mb,nb)  in prev_points:
                        P_vals[3] = 700
                    else:
                        jk = -2
                        data.write(str.encode("3"))
                        print("pb ---------------------")
                        val1 = data.readline().decode()
                        if int(val1) == 1:
                            uu = uu
                            vv = vv
                            P_vals[3] = 700
                            vvv = 1
                        else:
                            uu = mb
                            vv = nb
                            vvv = 0
                        break


        P_vals = []






