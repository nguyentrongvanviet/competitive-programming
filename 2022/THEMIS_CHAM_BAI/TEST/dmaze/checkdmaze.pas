{$MODE OBJFPC}
{$R-,Q-,S-,I-}
{$OPTIMIZATION LEVEL2}
program IntervalCover;
uses Windows, SysUtils, Math;
const
  InputFile  	= 'dmaze.INP';
  OutputFile 	= 'dmaze.OUT';
var
  dirT, dirC	        : WideString;
  ans,hsans             :       longint;
  ok1,ok2  		:       boolean;
  m,n,a,b,c,p,q,k       :       longint;
  res                   :       array[1..10000000] of longint;
  ocam                  :       array[1..10000000] of boolean;

procedure GenErr(const s: string; const param: array of const);
begin
  raise Exception.CreateFmt(s, param);
end;

procedure ReadDirs;
var
  s: AnsiString;
begin
  ReadLn(s); dirT := Utf8Decode(s);
  ReadLn(s); dirC := Utf8Decode(s);
end;
procedure Readin;
var
  f             : TextFile;
  i             :       longint;
begin
  SetCurrentDirectoryW(PWideChar(dirT));
  AssignFile(f, inputFile); Reset(f);
      Readln(f, m,n,k);
      readln(f, p,q,a,b,c);
      fillchar(ocam,sizeof(ocam),false);
      ocam[q] := true;
      for i := 2 to p do
          begin
             q := ((q*a + b) mod c) + 1;
             ocam[q] := true;
          end;
  CloseFile(f);
end;
procedure ReadAns;
var
  f: TextFile;
  i: longint;
begin
  SetCurrentDirectoryW(PWideChar(dirT));
  AssignFile(f, outputFile); Reset(f);
      Readln(f, ans);
  CloseFile(f);
end;

procedure AllTasks;
begin
  Readin;
  Readans;
end;

procedure DoCheck;
var
  f		: TextFile;
  i,u,dem       : longint;
begin
  AllTasks;
  SetCurrentDirectoryW(PWideChar(DirC));
  if not FileExists(OutputFile) then
    GenErr('Kh'#$C3#$B4'ng th'#$E1#$BA#$A5'y file %s', [OutputFile]);
  AssignFile(f, OutputFile); Reset(f);
  try
    Read(f, hsans);
    if ans <> hsans then
    Begin
      ok1:=False;
      GenErr('KET QUA SAI', []);
    End;
    if (ans <> -1) then
    begin
    dem := 0;
    while not seekeof(f) do
       begin
          inc(dem);
          read(f,u);
          if ocam[u] = true then
             begin
                 ok2 := false;
                 GenErr('DI VAO O CAM', []);
             end;
       end;
    if dem <> ans then
       begin
                 ok2 := false;
                 GenErr('SO O DI QUA KHAC DO DAI', []);
       end;
    end;
    WriteLn('KET QUA DUNG');
    WriteLn('1.0');
  finally
    CloseFile(f);
  end;
end;

begin

  ReadDirs;
  Write(#$EF#$BB#$BF); //Utf-8 BOM
  try
    ok1 := true; ok2 := true;
    DoCheck;
  except
    on E: Exception do
      begin
        WriteLn(E.Message);
        if ok1 then
           begin
               if not ok2 then WriteLn('0.3');
           end
        else writeln('0.0');
      end;
  end;
end.
