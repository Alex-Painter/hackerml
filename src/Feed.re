/* State declaration */
[@react.component]
let make = (~name) => {
  let (items, setItems) = React.useState(() => "");
  let fetchItems = (ids) => {
    let 
  }
  React.useEffect0(() => { 
    Js.Promise.(
      Axios.get("https://hacker-news.firebaseio.com/v0/topstories.json")
      |> then_((response) => resolve(setItems(response##data)))
      |> catch((error) => resolve(Js.log(error)))
    );
    Some(() => Js.log());
  }); 
  let message = "hello " ++ name;
  <div>
    {ReasonReact.string(items)}
    {ReasonReact.string(message)}
  </div>
}