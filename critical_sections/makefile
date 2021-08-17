all:
	FOR /D %i in (*) DO cd %i && nmake /NOLOGO && cd ..
clean:
	FOR /D %i in (*) DO cd %i && nmake /NOLOGO clean && cd ..