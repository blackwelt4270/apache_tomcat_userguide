/* 
遊戲收藏家 CAI=
物品展櫃 CAM=
打算交易的物品 CAQ=
徽章收藏家 CAU=
最喜愛的遊戲 CAY=
截圖 CAc=
自定義信息框 CAg=
最喜愛的組 CAk=
評測 CAo=
創意工坊 CAs=
您的創意工坊 CAw=
藝術作品 CA0=
視頻 CA4=
指南 CA8=
我的指南 CBA=
成就 CBE=
精選藝術作品 CBY=
完美主義者 CBc=
*/
// Token，訪問 https://store.steampowered.com/pointssummary/ajaxgetasyncconfig 獲取

const code = "填入上文你想要展櫃的標識符";
const token = "填入你獲取的token";
const formData = new FormData();
formData.append("input_protobuf_encoded", code);
fetch(`https://api.steampowered.com/ILoyaltyRewardsService/RedeemPointsForProfileCustomization/v1?access_token=${token}`, {
    method: "POST",
    mode: "cors",
    body: formData,
});
