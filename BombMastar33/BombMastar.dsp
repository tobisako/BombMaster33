# Microsoft Developer Studio Project File - Name="BombMastar" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=BombMastar - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "BombMastar.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "BombMastar.mak" CFG="BombMastar - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "BombMastar - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "BombMastar - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BombMastar - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "BombMastar - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "BombMastar - Win32 Release"
# Name "BombMastar - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BombListCnt.cpp
# End Source File
# Begin Source File

SOURCE=.\BombMastar.cpp
# End Source File
# Begin Source File

SOURCE=.\BombMastar.rc
# End Source File
# Begin Source File

SOURCE=.\BombMastarDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\BombMastarView.cpp
# End Source File
# Begin Source File

SOURCE=.\BombMastatToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MYTimerThread1.cpp
# End Source File
# Begin Source File

SOURCE=.\ScoreDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TimerDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BombListCnt.h
# End Source File
# Begin Source File

SOURCE=.\BombMastar.h
# End Source File
# Begin Source File

SOURCE=.\BombMastarDoc.h
# End Source File
# Begin Source File

SOURCE=.\BombMastarView.h
# End Source File
# Begin Source File

SOURCE=.\BombMastatToolBar.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ScoreDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TimerDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bomb5end.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Bomb8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BombEnd1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BombEnd2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BombEnd3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BombEnd4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BombMastar.ico
# End Source File
# Begin Source File

SOURCE=.\res\BombMastar.rc2
# End Source File
# Begin Source File

SOURCE=.\res\BombMastarDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\BombWhite.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BomeEnd1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bonbend3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cu010.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor3.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor4.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor5.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursorNew1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursorNew2.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursorNew3.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursorNew4.cur
# End Source File
# Begin Source File

SOURCE=.\res\GameEnd1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar3.bmp
# End Source File
# Begin Source File

SOURCE=".\res\爆弾1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\爆弾2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\爆弾3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\爆弾4.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
