import turtle

turtle.hideturtle()
turtle.penup()
turtle.goto(-180,-5)
turtle.write("West")
turtle.goto(-150,0)
turtle.pendown()

turtle.goto(150,0)

turtle.penup()
turtle.goto(160,-5)
turtle.write("East")
turtle.goto(150,0)
turtle.pendown()

turtle.penup()
turtle.goto(-8,150)
turtle.write("North")
turtle.goto(0,150)
turtle.pendown()

turtle.goto(0,-150)

turtle.penup()
turtle.goto(-8,-160)
turtle.write("South")
turtle.goto(-30,0)
turtle.seth(90)
turtle.pendown()

turtle.circle(-30)

turtle.done()