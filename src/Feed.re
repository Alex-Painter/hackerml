/* State declaration */
[@react.component]
let make = (~name) => {
  let (items, setItems) = React.useState(() => []);
  let fetchItems = () => {
    let items = [|"1", "2", "3"|]; //fetch items
    let articles = Js.Array.map(item => {
      Js.Promise.(
        Axios.get(" https://hacker-news.firebaseio.com/v0/item/"++item)
        |> then_((response) => {
          resolve((response##data));
        })
        |> catch((error) => resolve(Js.log(error)))
      );
      Some(() => Js.log());
    }, items);
    Js.log(articles);
  }

  fetchItems();
  React.useEffect0(() => { 
    Js.Promise.(
      Axios.get("https://hacker-news.firebaseio.com/v0/topstories.json")
      |> then_((response) => {
        Js.log(response##data);
        resolve(setItems(response##data));
      })
      |> catch((error) => resolve(Js.log(error)))
    );
    Some(() => Js.log());
  }); 
  let message = "hello " ++ name;
  <div>
    {ReasonReact.string(message)}
  </div>
}