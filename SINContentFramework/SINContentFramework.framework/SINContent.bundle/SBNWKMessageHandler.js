


// 初始化WebView
function webViewInit()
{
    // 文字长按不出复制
    //  document.documentElement.style.webkitUserSelect='none';
    // 图片长按不出复制
    document.documentElement.style.webkitTouchCallout='none';
    
    /*
     / 快速滑动，回弹效果。与-webkit-overflow-scrolling 相同
     创建了带有硬件加速的系统级控件，所以效率很高。但是这相对是耗更多内存的，最好在产生了非常大面积的overflow时才应用。
     如果发现以下情况关掉它：
     1.快速滚动时，导致Native滚动时出现黑色背景。有可能是这个带来的。
     2.some device or system heavy memory usage。
     */
//    document.getElementById('container').style.webkitOverflowScrolling = 'auto';
    
    // 去图片的边框
    imgOpacitySet();
    
}

// 改变字体
function changeWebViewTextFont(fontSize)
{
    var tags = ['body', 'p','div'] , i = 0 , j=0 , childs;
    for(i ; i < tags.length ; i++){
        childs = document.getElementsByTagName(tags[i]);
        for(j ; j < childs.length ; j++) {
           childs[j].style.fontSize = fontSize + 'px';
        }
        j= 0 ;
    }

}
//function imageClickAction(clickNum)
//{
//    
//    var imgH = document.getElementsByTagName("img")[clickNum].height;
//    var imgW = document.getElementsByTagName("img")[clickNum].width;
//    var imgX = document.getElementsByTagName("img")[clickNum].offsetLeft;
//    var imgY = document.getElementsByTagName("img")[clickNum].offsetTop;
//    
//    var message = { 'funcName' : 'imageClickAction','clickNum' : clickNum, 'frame' : [ imgX, imgY, imgW,imgH ] };
//    window.webkit.messageHandlers.SBNDetailWKWebJS.postMessage(JSON.stringify(message));
//}
//

function imgOpacitySet(){
    var _oImges = document.getElementsByTagName('img');
    for(var i = 0,len = _oImges.length; i < len; i++){
        var _sImgSrc = _oImges[i].getAttribute("src");
        if(_sImgSrc == "Detail_loading"){
            _oImges[i].style.opacity = 0;
        }
    }
}

function getAllimgViewFrame()
{
    var images = document.getElementsByTagName("img");
    var imgViewFrame = [];
    for(var i = 0,len = images.length; i < len; i++){
        var imgH = images[i].height ;
        var imgW = images[i].width ;
        var imgX = images[i].offsetLeft ;
        var imgY = images[i].offsetTop;
        imgViewFrame.push({
            imgH : imgH,
            imgW : imgW,
            imgX : imgX,
            imgY : imgY
        });
    }
    return imgViewFrame;
}

function removePlaceholder(ele){
    if(ele.style.opacity === ""){
        ele.style.opacity = 1;
    }
    if(ele.style.display === "" || ele.style.display === 'none'){
        ele.style.display = 'block';
    }
    
    var t = setInterval(function(){
                if(ele.style.opacity >= 0){
                    ele.style.opacity = Math.floor(ele.style.opacity*100)/100-0.5;
                }
                else{
                    clearInterval(t);
                    ele.style.display = 'none'
                    ele.parentNode.removeChild(ele);
                }
            },1);
}

// 改变某一张图片的宽高。
function imgSizeSet(option){
    var _oImg = document.getElementById(option.id);
    _oImg.style.width = option.width+"px";
    _oImg.style.height = option.height+"px";
}


function removeAllPlaceholder(){
    var placeholderes = document.getElementsByClassName("imgPlaceholder");
    for(var i=0,len=placeholderes.length;i<len;i++){
        placeholderes[i].parentNode.removeChild(placeholderes[i]);
//        document.body.removeChild(placeholderes[i]);
    }
}

window.onload = webViewInit;


