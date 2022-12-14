; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[Item.Shape:S]
X=(30*[Set.S])
Y=(35*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.StringIcon:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
StringAlign=leftCenter
FontFace=Segoe Fluent Icons
Container=ContentContainer
[Item.String:S]
X=(#Set.P#/2)R
Y=r
StringAlign=LeftCenter
Container=ContentContainer
[Item.Arrow.String:S]
X=([ContentContainer:W]-#Set.P#)
Y=r
StringAlign=RightCenter
Text=>
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
GetIcon=0
ReturnValue=WholePath
FileInitialDirectory=
DynamicVariables=1
Command1=[!WriteKeyvalue Variables ImagePath "$Path$" "#Sec.SaveLocatioN#"][!UpdateMeasure Auto_Refresh:M]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[WelcomeHeader]
Meter=String
Text="Welcome to Overlayer"
MeterStyle=Set.String:S | Set.OptionCat:S

[Item1.Shape]
Meter=Shape
LeftMouseUpAction=["https://wiki.jaxcore.app/widgets/overlayer"]
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe81e]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=How do I use this to make cool layering effects with widgets?
MeterStyle=Set.String:S | Item.String:S
[Item1.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S

[PrefixTextHeader]
Meter=String
Text="Overlayer settings"
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text="Layering image"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text="Image fit"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text="Automated positioning"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text="Monitor to display on"
FontColor=#Set.Text_Color#,(105+150*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:7]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text="Custom X position"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text="Custom Y position"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text="Custom W dimension"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text="Custom H dimension"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 1"]
OverColor=#Set.Accent_Color#,150
LeaveColor=#Set.Accent_Color#,50
[Value01]
Meter=String
Text=#ImageName#
MeterStyle=Set.String:S | Set.Value:S

[PreserveAspectRatio:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('PreserveAspectRatio', '1')]+[&Func:returnBool('PreserveAspectRatio', '2')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
0Act=[!WriteKeyValue Variables PreserveAspectRatio "0" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables PreserveAspectRatio "1" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables PreserveAspectRatio "2" "#Sec.SaveLocation#"]
[PreserveAspectRatio:0]
Meter=String
Text="Stretch to fit"
FontColor=[&Func:returnBool('PreserveAspectRatio', '0', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
[PreserveAspectRatio:1]
Meter=String
Text="Fit"
FontColor=[&Func:returnBool('PreserveAspectRatio', '1', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
[PreserveAspectRatio:2]
Meter=String
Text="Fill"
FontColor=[&Func:returnBool('PreserveAspectRatio', '2', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S

[Automated]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[MonitorIndex]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#Automated#)
[Value03]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#MonitorIndex#
Hidden=(1-#Automated#)

[X]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value04]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#X#
Hidden=#Automated#
[Y]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value05]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#Y#
Hidden=#Automated#
[W]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value06]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#W#
Hidden=#Automated#
[H]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value07]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#H#
Hidden=#Automated#
[Variables]
Sec.Generate=1
page.page=2
