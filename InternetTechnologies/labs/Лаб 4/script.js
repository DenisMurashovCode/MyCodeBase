let images=["Kolya.jpg","Kolya1.jpg"]
let index=0;
let count=3;

let picture=document.getElementById("pictureBox");
let picture1=document.getElementById("pictureBox1");
let path=document.getElementById("textbox");


nextbutton.onclick=function()
{
    if(index==1)
        index=0;
    else{
        index=1;
    }
    picture.style.backgroundImage="url("+images[index]+")";
    
   if(index==0)
        index=1;
    else{
        index=0;
    }
    
    picture1.style.backgroundImage="url("+images[index]+")";
    index++;
   
}